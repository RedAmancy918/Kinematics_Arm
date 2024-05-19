#include "arm_sys.h"
#include <iostream>
#include <pigpio.h>
#include <vector>
#include <thread>
#include <functional>
#include <sstream>
#include <string>
#include <unistd.h>

// Initialize static member variables
bool mg90s::initialized = false;
int mg90s::instances = 0;

// Constructor
mg90s::mg90s(int gpioPin, float initialAngle) : pin(gpioPin), currentAngle(initialAngle) {
    // Initialize the pigpio library if it hasn't been initialized yet
    if (!initialized) {
        if (gpioInitialise() < 0) {
            std::cerr << "pigpio initialization failed." << std::endl;
            exit(1);
        }
        initialized = true;
    }
    instances++;

    // Optionally: Move the servo to its initial position
    gpioServo(pin, angleToPulseWidth(currentAngle));
}

// Destructor
mg90s::~mg90s() {
    // Terminate the pigpio library if this is the last instance
    if (--instances <= 0) {
        gpioTerminate();
    }
}

// Asynchronously set the target angle
void mg90s::setTargetAngleAsync(float angle, CallbackFunction callback) {
    onTargetReached = callback; // Store the callback function
    std::thread(&mg90s::detectAngle, this, angle).detach(); // Create and detach a thread to move the servo asynchronously
}

// Angle pre-processing
void mg90s::detectAngle(float angle) {
    if (angle < -90) {
        angle = -90;
    } else if (angle > 90) {
        angle = 90;
    }
    moveToAngleSlowly(angle);
}

// Private method to smoothly move to the target angle
void mg90s::moveToAngleSlowly(float targetAngle) {
    float step = (targetAngle > currentAngle) ? 1 : -1; // Determine the step direction

    while (currentAngle != targetAngle) {
        currentAngle += step;
        if ((step > 0 && currentAngle > targetAngle) || (step < 0 && currentAngle < targetAngle)) {
            currentAngle = targetAngle; // Prevent overshooting
        }
        int pulseWidth = angleToPulseWidth(currentAngle);
        gpioServo(pin, pulseWidth); // Set the servo angle
        usleep(20000); // 20ms delay to simulate smooth movement
    }

    if (onTargetReached) {
        onTargetReached(); // Call the callback function after the movement is complete
    }
}

// Convert angle to PWM pulse width
int mg90s::angleToPulseWidth(float angle) {
    return static_cast<int>((angle + 90) * (2000.0 / 180.0) + 500);
}






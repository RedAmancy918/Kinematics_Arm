#ifndef ARM_SYS_H
#define ARM_SYS_H

#include <functional> // For std::function

class mg90s
{
public:
    using CallbackFunction = std::function<void()>;

    // define the input
    mg90s(int gpioPin, float initialAngle = 0.0);

    ~mg90s();

    void setTargetAngleAsync(float angle, CallbackFunction callback = nullptr);

private:
    static bool initialized;
    static int instances;
    int pin;
    float currentAngle; // No need to change this
    CallbackFunction onTargetReached;

    void moveToAngleSlowly(float targetAngle);
    int angleToPulseWidth(float angle);
    void detectAngle(float angle);
};

#endif // ARM_SYS_H

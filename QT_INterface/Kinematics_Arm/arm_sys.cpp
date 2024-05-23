#include "arm_sys.h"
#include <QDebug>
#include <QThread>
#include <QtConcurrent/QtConcurrentRun>
#include "pigpio.h"
#include <QCoreApplication>

bool ArmSys::initialized = false;
int ArmSys::instances = 0;

ArmSys::ArmSys(int gpioPin, float initialAngle) : QObject(), pin(gpioPin), currentAngle(initialAngle) {
    if (!initialized) {
        if (gpioInitialise() < 0) {
            qDebug() << "PIGPIO initialization failed.";
            QCoreApplication::exit(-1);  // 更优雅的错误处理方式
        }
        initialized = true;
    }
    instances++;
    gpioServo(pin, angleToPulseWidth(currentAngle));
}

ArmSys::~ArmSys() {
    if (--instances <= 0) {
        gpioTerminate();
    }
}

void ArmSys::setTargetAngleAsync(float angle) {
    QtConcurrent::run(this, &ArmSys::detectAndMoveToAngle, angle);
}

void ArmSys::detectAndMoveToAngle(float angle) {
    if (angle < -90) angle = -90;
    else if (angle > 90) angle = 90;

    moveToAngleSlowly(angle);
}

void ArmSys::moveToAngleSlowly(float targetAngle) {
    float step = (targetAngle > currentAngle) ? 1 : -1;
    while (currentAngle != targetAngle) {
        currentAngle += step;
        if ((step > 0 && currentAngle > targetAngle) || (step < 0 && currentAngle < targetAngle)) {
            currentAngle = targetAngle;
        }
        int pulseWidth = angleToPulseWidth(currentAngle);
        gpioServo(pin, pulseWidth);
        QThread::msleep(20);
    }
    emit operationCompleted();  // 发射操作完成信号
}

int ArmSys::angleToPulseWidth(float angle) {
    return static_cast<int>((angle + 90) * (2000.0 / 180.0) + 500);
}

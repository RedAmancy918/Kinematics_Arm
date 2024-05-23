#ifndef ARM_SYS_H
#define ARM_SYS_H

#include <QObject>
#include <functional>

class ArmSys : public QObject {
    Q_OBJECT

public:
    using CallbackFunction = std::function<void()>;

    explicit ArmSys(int gpioPin, float initialAngle = 0.0);
    virtual ~ArmSys();

    void setTargetAngleAsync(float angle);

signals:
    void operationCompleted();

private:
    static bool initialized;
    static int instances;
    int pin;
    float currentAngle;

    void detectAndMoveToAngle(float angle);
    void moveToAngleSlowly(float targetAngle);
    int angleToPulseWidth(float angle);
};

#endif // ARM_SYS_H

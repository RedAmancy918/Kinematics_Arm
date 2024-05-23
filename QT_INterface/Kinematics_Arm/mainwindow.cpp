#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSlider>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , motor1(21)  // 假设第一个电机连接到 GPIO 21
    , motor2(20)  // 假设第二个电机连接到 GPIO 20
    , motor3(19)  // 假设第三个电机连接到 GPIO 19
    , motor4(6)   // 假设第四个电机连接到 GPIO 6
{
    ui->setupUi(this);

    // 查找 UI 中的 QSlider 控件
    QSlider *rotationSlider = findChild<QSlider*>("Rotation");
    QSlider *fixtureSlider = findChild<QSlider*>("Fixture");
    QSlider *firstArmSlider = findChild<QSlider*>("First_arm");
    QSlider *secondArmSlider = findChild<QSlider*>("Second_arm");

    // 查找 UI 中的 QLabel 控件
    QLabel *rotationLabel = findChild<QLabel*>("Rotation_value");
    QLabel *firstValueLabel = findChild<QLabel*>("First_value");
    QLabel *secondValueLabel = findChild<QLabel*>("Second_value");
    QLabel *fixtureLabel = findChild<QLabel*>("Fixture_value");

    // 连接 QSlider 的 valueChanged 信号到相应的处理函数
    connect(rotationSlider, &QSlider::valueChanged, [this, rotationLabel](int value) {
        rotationLabel->setText(QString::number(value));
        qDebug() << "Rotation Slider value: " << value;
        motor1.setTargetAngleAsync(value);
    });

    connect(fixtureSlider, &QSlider::valueChanged, [this, fixtureLabel](int value) {
        fixtureLabel->setText(QString::number(value));
        qDebug() << "Fixture Slider value: " << value;
        int mappedValue = value * 115 / 100 - 90;  // 根据需要调整映射
        motor4.setTargetAngleAsync(mappedValue);
    });

    connect(firstArmSlider, &QSlider::valueChanged, [this, firstValueLabel](int value) {
        firstValueLabel->setText(QString::number(value));
        qDebug() << "First Arm Slider value: " << value;
        motor2.setTargetAngleAsync(value);
    });

    connect(secondArmSlider, &QSlider::valueChanged, [this, secondValueLabel](int value) {
        secondValueLabel->setText(QString::number(value));
        qDebug() << "Second Arm Slider value: " << value;
        motor3.setTargetAngleAsync(value);
    });

    // 初始化显示滑块的当前值
    rotationLabel->setText(QString::number(rotationSlider->value()));
    firstValueLabel->setText(QString::number(firstArmSlider->value()));
    secondValueLabel->setText(QString::number(secondArmSlider->value()));
    fixtureLabel->setText(QString::number(fixtureSlider->value()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

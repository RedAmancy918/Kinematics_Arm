#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , motor1(21)
    , motor2(20)
    , motor3(19)
    , motor4(6)
{
    ui->setupUi(this);

    //  QSlider
    QSlider *Rotation = findChild<QSlider*>("Rotation");
    QSlider *Fixture = findChild<QSlider*>("Fixture");
    QSlider *First_arm = findChild<QSlider*>("First_arm");
    QSlider *Second_arm = findChild<QSlider*>("Second_arm");

    //  QLabel
    QLabel *Rotation_label = findChild<QLabel*>("Rotation_value");
    QLabel *First_value = findChild<QLabel*>("First_value");
    QLabel *Second_value = findChild<QLabel*>("Second_value");
    QLabel *Fixture_value = findChild<QLabel*>("Fixture_value");

    // 连接 QSlider 的 valueChanged 到槽函数
    connect(Rotation, &QSlider::valueChanged, this, &MainWindow::onRotationValueChanged);
    connect(Fixture, &QSlider::valueChanged, this, &MainWindow::onFixtureValueChanged);
    connect(First_arm, &QSlider::valueChanged, this, &MainWindow::onFirstArmValueChanged);
    connect(Second_arm, &QSlider::valueChanged, this, &MainWindow::onSecondArmValueChanged);

    // 初始化一下
    Rotation_label->setText(QString::number(Rotation->value()));
    First_value->setText(QString::number(First_arm->value()));
    Second_value->setText(QString::number(Second_arm->value()));
    Fixture_value->setText(QString::number(Fixture->value()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onRotationValueChanged(int value)
{
    // 更新标签显示当前滑块值
    QLabel *Rotation_label = findChild<QLabel*>("rotation_value");
    Rotation_label->setText(QString::number(value));
    qDebug() << "Rotation Slider value: " << value;


    motor1.setTargetAngleAsync(value);
}

void MainWindow::onFirstArmValueChanged(int value)
{
    // 更新标签显示当前滑块值
    QLabel *First_value = findChild<QLabel*>("first_value");
    First_value->setText(QString::number(value));
    qDebug() << "First Arm Slider value: " << value;


    motor2.setTargetAngleAsync(value);
}

void MainWindow::onSecondArmValueChanged(int value)
{
    // 更新标签显示当前滑块值
    QLabel *Second_value = findChild<QLabel*>("second_value");
    Second_value->setText(QString::number(value));
    qDebug() << "Second Arm Slider value: " << value;


    motor3.setTargetAngleAsync(value);
}

void MainWindow::onFixtureValueChanged(int value)
{
    // 更新标签显示当前滑块值
    QLabel *Fixture_value = findChild<QLabel*>("fixture_value");
    Fixture_value->setText(QString::number(value));
    qDebug() << "Fixture Slider value: " << value;


    int mapped_value = value * 115 / 100 - 90;
    motor4.setTargetAngleAsync(mapped_value);
}

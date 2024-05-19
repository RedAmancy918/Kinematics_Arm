#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arm_sys.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onRotationValueChanged(int value);
    void onFirstArmValueChanged(int value);
    void onSecondArmValueChanged(int value);
    void onFixtureValueChanged(int value);

private:
    Ui::MainWindow *ui;
    mg90s motor1;
    mg90s motor2;
    mg90s motor3;
    mg90s motor4;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QLabel>

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
    void onSliderValueChacnged(int value);

private:
    Ui::MainWindow *ui;
    QSlider *slider;
    QLabel *valueLabel;
     ArmController armController;
};
#endif // MAINWINDOW_H

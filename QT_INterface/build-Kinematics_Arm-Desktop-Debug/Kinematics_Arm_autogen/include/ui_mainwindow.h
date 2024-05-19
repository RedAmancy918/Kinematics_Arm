/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *Rotation;
    QSlider *First_arm;
    QSlider *Second_arm;
    QSlider *Fixture;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *Rotation_value;
    QLabel *Fixture_value;
    QLabel *First_value;
    QLabel *Second_value;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QPushButton *pushButton;
    QLabel *label_5;
    QPushButton *Add;
    QTextEdit *textEdit;
    QComboBox *armTypeComboBox;
    QComboBox *endEffectorComboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Rotation = new QSlider(centralwidget);
        Rotation->setObjectName(QString::fromUtf8("Rotation"));
        Rotation->setGeometry(QRect(130, 150, 160, 16));
        Rotation->setMinimum(-90);
        Rotation->setMaximum(90);
        Rotation->setOrientation(Qt::Horizontal);
        First_arm = new QSlider(centralwidget);
        First_arm->setObjectName(QString::fromUtf8("First_arm"));
        First_arm->setGeometry(QRect(100, 190, 16, 160));
        First_arm->setMinimum(-90);
        First_arm->setMaximum(90);
        First_arm->setOrientation(Qt::Vertical);
        Second_arm = new QSlider(centralwidget);
        Second_arm->setObjectName(QString::fromUtf8("Second_arm"));
        Second_arm->setGeometry(QRect(290, 190, 16, 160));
        Second_arm->setMinimum(-90);
        Second_arm->setMaximum(90);
        Second_arm->setOrientation(Qt::Vertical);
        Fixture = new QSlider(centralwidget);
        Fixture->setObjectName(QString::fromUtf8("Fixture"));
        Fixture->setGeometry(QRect(130, 370, 160, 16));
        Fixture->setMinimum(-90);
        Fixture->setMaximum(25);
        Fixture->setOrientation(Qt::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 130, 67, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 350, 67, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 250, 67, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(320, 260, 91, 17));
        Rotation_value = new QLabel(centralwidget);
        Rotation_value->setObjectName(QString::fromUtf8("Rotation_value"));
        Rotation_value->setGeometry(QRect(170, 170, 67, 17));
        Fixture_value = new QLabel(centralwidget);
        Fixture_value->setObjectName(QString::fromUtf8("Fixture_value"));
        Fixture_value->setGeometry(QRect(180, 390, 67, 17));
        First_value = new QLabel(centralwidget);
        First_value->setObjectName(QString::fromUtf8("First_value"));
        First_value->setGeometry(QRect(30, 270, 67, 17));
        Second_value = new QLabel(centralwidget);
        Second_value->setObjectName(QString::fromUtf8("Second_value"));
        Second_value->setGeometry(QRect(320, 280, 67, 17));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(450, 190, 61, 26));
        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(530, 190, 61, 26));
        spinBox_3 = new QSpinBox(centralwidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(610, 190, 61, 26));
        spinBox_4 = new QSpinBox(centralwidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(690, 190, 61, 26));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(610, 270, 141, 25));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(450, 90, 301, 71));
        Add = new QPushButton(centralwidget);
        Add->setObjectName(QString::fromUtf8("Add"));
        Add->setGeometry(QRect(450, 270, 141, 25));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(450, 310, 301, 141));
        armTypeComboBox = new QComboBox(centralwidget);
        armTypeComboBox->addItem(QString());
        armTypeComboBox->addItem(QString());
        armTypeComboBox->addItem(QString());
        armTypeComboBox->addItem(QString());
        armTypeComboBox->setObjectName(QString::fromUtf8("armTypeComboBox"));
        armTypeComboBox->setGeometry(QRect(450, 230, 141, 25));
        endEffectorComboBox = new QComboBox(centralwidget);
        endEffectorComboBox->addItem(QString());
        endEffectorComboBox->addItem(QString());
        endEffectorComboBox->addItem(QString());
        endEffectorComboBox->setObjectName(QString::fromUtf8("endEffectorComboBox"));
        endEffectorComboBox->setGeometry(QRect(610, 230, 141, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Fixture", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "First Arm", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Second Arm", nullptr));
        Rotation_value->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Fixture_value->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        First_value->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Second_value->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Calcuate", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        Add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        armTypeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Choose arm type\351\230\277", nullptr));
        armTypeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Cartesian", nullptr));
        armTypeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Spherical coordinates", nullptr));
        armTypeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Cylindrical coordinates", nullptr));

        endEffectorComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Select EndEffect", nullptr));
        endEffectorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "RPY", nullptr));
        endEffectorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Euler", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

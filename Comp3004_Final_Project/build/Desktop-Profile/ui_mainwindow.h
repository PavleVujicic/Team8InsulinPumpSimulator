/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.18
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtCharts/QChartView"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Page1;
    QPushButton *createProfile;
    QLabel *profileLabel;
    QPushButton *Start;
    QWidget *profiles;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *profileLayout;
    QPushButton *updateProfile;
    QPushButton *deleteProfile;
    QWidget *Page2;
    QLabel *label;
    QLineEdit *ProfileName;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *BasalRates;
    QLineEdit *CorrectionFactor;
    QLineEdit *Carbohydrate;
    QPushButton *SubmitForm;
    QLabel *label_7;
    QLineEdit *Pin;
    QWidget *page3;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLineEdit *ProfileName2;
    QLineEdit *BasalRates2;
    QLineEdit *Carbohydrate2;
    QLineEdit *CorrectionFactor2;
    QLineEdit *Pin2;
    QPushButton *Update;
    QWidget *page4;
    QLabel *label_6;
    QChartView *chartContainer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 532);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 791, 501));
        Page1 = new QWidget();
        Page1->setObjectName(QString::fromUtf8("Page1"));
        createProfile = new QPushButton(Page1);
        createProfile->setObjectName(QString::fromUtf8("createProfile"));
        createProfile->setGeometry(QRect(260, 420, 141, 41));
        profileLabel = new QLabel(Page1);
        profileLabel->setObjectName(QString::fromUtf8("profileLabel"));
        profileLabel->setGeometry(QRect(300, 10, 151, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(20);
        font.setBold(true);
        profileLabel->setFont(font);
        Start = new QPushButton(Page1);
        Start->setObjectName(QString::fromUtf8("Start"));
        Start->setGeometry(QRect(60, 420, 101, 51));
        profiles = new QWidget(Page1);
        profiles->setObjectName(QString::fromUtf8("profiles"));
        profiles->setGeometry(QRect(49, 59, 681, 361));
        verticalLayoutWidget = new QWidget(profiles);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 651, 341));
        profileLayout = new QVBoxLayout(verticalLayoutWidget);
        profileLayout->setSpacing(5);
        profileLayout->setObjectName(QString::fromUtf8("profileLayout"));
        profileLayout->setContentsMargins(0, 0, 0, 0);
        updateProfile = new QPushButton(Page1);
        updateProfile->setObjectName(QString::fromUtf8("updateProfile"));
        updateProfile->setGeometry(QRect(570, 420, 161, 41));
        deleteProfile = new QPushButton(Page1);
        deleteProfile->setObjectName(QString::fromUtf8("deleteProfile"));
        deleteProfile->setGeometry(QRect(430, 420, 111, 41));
        stackedWidget->addWidget(Page1);
        Page2 = new QWidget();
        Page2->setObjectName(QString::fromUtf8("Page2"));
        label = new QLabel(Page2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 251, 41));
        label->setFont(font);
        ProfileName = new QLineEdit(Page2);
        ProfileName->setObjectName(QString::fromUtf8("ProfileName"));
        ProfileName->setGeometry(QRect(210, 100, 141, 31));
        label_2 = new QLabel(Page2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 100, 131, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans"));
        font1.setPointSize(11);
        label_2->setFont(font1);
        label_3 = new QLabel(Page2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 150, 131, 41));
        label_3->setFont(font1);
        label_4 = new QLabel(Page2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 200, 151, 41));
        label_4->setFont(font1);
        label_5 = new QLabel(Page2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 250, 141, 41));
        label_5->setFont(font1);
        BasalRates = new QLineEdit(Page2);
        BasalRates->setObjectName(QString::fromUtf8("BasalRates"));
        BasalRates->setGeometry(QRect(210, 150, 141, 31));
        CorrectionFactor = new QLineEdit(Page2);
        CorrectionFactor->setObjectName(QString::fromUtf8("CorrectionFactor"));
        CorrectionFactor->setGeometry(QRect(210, 250, 141, 31));
        Carbohydrate = new QLineEdit(Page2);
        Carbohydrate->setObjectName(QString::fromUtf8("Carbohydrate"));
        Carbohydrate->setGeometry(QRect(210, 200, 141, 31));
        SubmitForm = new QPushButton(Page2);
        SubmitForm->setObjectName(QString::fromUtf8("SubmitForm"));
        SubmitForm->setGeometry(QRect(160, 390, 101, 31));
        label_7 = new QLabel(Page2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(90, 300, 91, 41));
        label_7->setFont(font1);
        Pin = new QLineEdit(Page2);
        Pin->setObjectName(QString::fromUtf8("Pin"));
        Pin->setGeometry(QRect(210, 310, 141, 31));
        stackedWidget->addWidget(Page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        label_19 = new QLabel(page3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(70, 90, 111, 41));
        label_19->setFont(font1);
        label_20 = new QLabel(page3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(80, 140, 101, 41));
        label_20->setFont(font1);
        label_21 = new QLabel(page3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(20, 190, 151, 41));
        label_21->setFont(font1);
        label_22 = new QLabel(page3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(40, 260, 141, 41));
        label_22->setFont(font1);
        label_23 = new QLabel(page3);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(100, 330, 91, 41));
        label_23->setFont(font1);
        label_24 = new QLabel(page3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(80, 30, 301, 41));
        label_24->setFont(font);
        ProfileName2 = new QLineEdit(page3);
        ProfileName2->setObjectName(QString::fromUtf8("ProfileName2"));
        ProfileName2->setGeometry(QRect(220, 90, 141, 31));
        BasalRates2 = new QLineEdit(page3);
        BasalRates2->setObjectName(QString::fromUtf8("BasalRates2"));
        BasalRates2->setGeometry(QRect(220, 140, 141, 31));
        Carbohydrate2 = new QLineEdit(page3);
        Carbohydrate2->setObjectName(QString::fromUtf8("Carbohydrate2"));
        Carbohydrate2->setGeometry(QRect(220, 190, 141, 31));
        CorrectionFactor2 = new QLineEdit(page3);
        CorrectionFactor2->setObjectName(QString::fromUtf8("CorrectionFactor2"));
        CorrectionFactor2->setGeometry(QRect(220, 260, 141, 31));
        Pin2 = new QLineEdit(page3);
        Pin2->setObjectName(QString::fromUtf8("Pin2"));
        Pin2->setGeometry(QRect(220, 330, 141, 31));
        Update = new QPushButton(page3);
        Update->setObjectName(QString::fromUtf8("Update"));
        Update->setGeometry(QRect(130, 400, 101, 31));
        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QString::fromUtf8("page4"));
        label_6 = new QLabel(page4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(320, 10, 101, 41));
        chartContainer = new QChartView(page4);
        chartContainer->setObjectName(QString::fromUtf8("chartContainer"));
        chartContainer->setGeometry(QRect(70, 50, 581, 311));
        chartContainer->setFrameShape(QFrame::Shape::StyledPanel);
        chartContainer->setFrameShadow(QFrame::Shadow::Raised);
        stackedWidget->addWidget(page4);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 36));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        createProfile->setText(QCoreApplication::translate("MainWindow", "Create new Profile", nullptr));
        profileLabel->setText(QCoreApplication::translate("MainWindow", "Profiles:", nullptr));
        Start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        updateProfile->setText(QCoreApplication::translate("MainWindow", "Read Or Update Profile", nullptr));
        deleteProfile->setText(QCoreApplication::translate("MainWindow", "Delete Profile", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Create a Profile:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Profile Name:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Basal Rates:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Carbohydrate Ratio:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Correction Factor:", nullptr));
        SubmitForm->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Profile Pin:", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Profile Name:", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Basal Rates:", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Carbohydrate Ratio:", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Correction Factor:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Profile Pin:", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Update the Profile:", nullptr));
        Update->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Home Screen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

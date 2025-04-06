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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
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
    QChartView *chartContainer;
    QLabel *label_8;
    QToolButton *btnOptions;
    QToolButton *btnBolus;
    QLabel *label_9;
    QFrame *frame;
    QLabel *Glucose_tracker;
    QLabel *label_11;
    QLabel *ARROW;
    QLabel *iconLabel;
    QLabel *STATE_OUTPUT;
    QPushButton *EatFood;
    QLabel *label_6;
    QPushButton *btnStopBolus;
    QLabel *lblRemainingBolus;
    QLabel *lblRemainingOnboard;
    QProgressBar *barBattery;
    QLabel *label_12;
    QLabel *label_13;
    QProgressBar *barOnBoard;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *lblTime;
    QSlider *sliFood;
    QLabel *lblFood;
    QWidget *PageBolus;
    QLineEdit *txtInsulinAmount;
    QLineEdit *txtGlucoseAmount;
    QPushButton *btnBolusBack;
    QPushButton *btnBolusStart;
    QLineEdit *txtBolusInstant;
    QLabel *label_81;
    QLabel *label_91;
    QPushButton *btnScanGlucose;
    QLabel *label_10;
    QRadioButton *radUseInsulin;
    QRadioButton *radUseCarbs;
    QPushButton *btnBolusCalculate;
    QFrame *line;
    QLabel *label_14;
    QLineEdit *txtBolusLongterm;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *txtBolusRate;
    QLabel *label_17;
    QRadioButton *radDeliveryImmediate;
    QRadioButton *radDeliveryExtended;
    QLabel *label_18;
    QLabel *label_25;
    QWidget *PageOptions;
    QLabel *label_28;
    QPushButton *btnOptionsProfiles;
    QPushButton *btnOptionsHistory;
    QPushButton *btnOptionsHome;
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
        font.setWeight(75);
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
        chartContainer = new QChartView(page4);
        chartContainer->setObjectName(QString::fromUtf8("chartContainer"));
        chartContainer->setGeometry(QRect(0, 50, 571, 331));
        chartContainer->setMaximumSize(QSize(581, 16777215));
        chartContainer->setFrameShape(QFrame::NoFrame);
        label_8 = new QLabel(page4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 20, 51, 16));
        btnOptions = new QToolButton(page4);
        btnOptions->setObjectName(QString::fromUtf8("btnOptions"));
        btnOptions->setGeometry(QRect(10, 410, 181, 41));
        btnOptions->setCheckable(false);
        btnBolus = new QToolButton(page4);
        btnBolus->setObjectName(QString::fromUtf8("btnBolus"));
        btnBolus->setGeometry(QRect(220, 410, 241, 41));
        label_9 = new QLabel(page4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(480, 20, 51, 16));
        frame = new QFrame(page4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(610, 110, 151, 181));
        frame->setFrameShape(QFrame::NoFrame);
        Glucose_tracker = new QLabel(frame);
        Glucose_tracker->setObjectName(QString::fromUtf8("Glucose_tracker"));
        Glucose_tracker->setGeometry(QRect(10, 10, 101, 61));
        QFont font2;
        font2.setPointSize(30);
        Glucose_tracker->setFont(font2);
        Glucose_tracker->setTextFormat(Qt::PlainText);
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 70, 151, 41));
        label_11->setFont(font2);
        ARROW = new QLabel(frame);
        ARROW->setObjectName(QString::fromUtf8("ARROW"));
        ARROW->setGeometry(QRect(50, 120, 121, 51));
        QFont font3;
        font3.setPointSize(33);
        ARROW->setFont(font3);
        iconLabel = new QLabel(page4);
        iconLabel->setObjectName(QString::fromUtf8("iconLabel"));
        iconLabel->setGeometry(QRect(530, 0, 81, 41));
        STATE_OUTPUT = new QLabel(page4);
        STATE_OUTPUT->setObjectName(QString::fromUtf8("STATE_OUTPUT"));
        STATE_OUTPUT->setGeometry(QRect(60, 20, 71, 16));
        EatFood = new QPushButton(page4);
        EatFood->setObjectName(QString::fromUtf8("EatFood"));
        EatFood->setGeometry(QRect(570, 390, 121, 41));
        label_6 = new QLabel(page4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(530, 430, 221, 21));
        btnStopBolus = new QPushButton(page4);
        btnStopBolus->setObjectName(QString::fromUtf8("btnStopBolus"));
        btnStopBolus->setEnabled(false);
        btnStopBolus->setGeometry(QRect(402, 450, 61, 29));
        lblRemainingBolus = new QLabel(page4);
        lblRemainingBolus->setObjectName(QString::fromUtf8("lblRemainingBolus"));
        lblRemainingBolus->setGeometry(QRect(310, 450, 81, 20));
        lblRemainingOnboard = new QLabel(page4);
        lblRemainingOnboard->setObjectName(QString::fromUtf8("lblRemainingOnboard"));
        lblRemainingOnboard->setGeometry(QRect(680, 20, 81, 20));
        barBattery = new QProgressBar(page4);
        barBattery->setObjectName(QString::fromUtf8("barBattery"));
        barBattery->setGeometry(QRect(70, 0, 91, 23));
        barBattery->setValue(100);
        label_12 = new QLabel(page4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 0, 63, 20));
        label_13 = new QLabel(page4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(220, 450, 81, 20));
        barOnBoard = new QProgressBar(page4);
        barOnBoard->setObjectName(QString::fromUtf8("barOnBoard"));
        barOnBoard->setGeometry(QRect(690, 0, 91, 23));
        barOnBoard->setValue(100);
        label_26 = new QLabel(page4);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(640, 0, 63, 20));
        label_27 = new QLabel(page4);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(260, 0, 151, 16));
        lblTime = new QLabel(page4);
        lblTime->setObjectName(QString::fromUtf8("lblTime"));
        lblTime->setGeometry(QRect(220, 10, 231, 41));
        QFont font4;
        font4.setPointSize(24);
        font4.setBold(true);
        font4.setWeight(75);
        lblTime->setFont(font4);
        sliFood = new QSlider(page4);
        sliFood->setObjectName(QString::fromUtf8("sliFood"));
        sliFood->setGeometry(QRect(550, 450, 160, 21));
        sliFood->setMinimum(1);
        sliFood->setMaximum(3);
        sliFood->setSliderPosition(2);
        sliFood->setTickPosition(QSlider::NoTicks);
        sliFood->setTickInterval(1);
        lblFood = new QLabel(page4);
        lblFood->setObjectName(QString::fromUtf8("lblFood"));
        lblFood->setGeometry(QRect(550, 470, 161, 20));
        stackedWidget->addWidget(page4);
        PageBolus = new QWidget();
        PageBolus->setObjectName(QString::fromUtf8("PageBolus"));
        txtInsulinAmount = new QLineEdit(PageBolus);
        txtInsulinAmount->setObjectName(QString::fromUtf8("txtInsulinAmount"));
        txtInsulinAmount->setGeometry(QRect(110, 260, 221, 101));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        txtInsulinAmount->setFont(font5);
        txtGlucoseAmount = new QLineEdit(PageBolus);
        txtGlucoseAmount->setObjectName(QString::fromUtf8("txtGlucoseAmount"));
        txtGlucoseAmount->setGeometry(QRect(360, 260, 221, 101));
        txtGlucoseAmount->setFont(font5);
        btnBolusBack = new QPushButton(PageBolus);
        btnBolusBack->setObjectName(QString::fromUtf8("btnBolusBack"));
        btnBolusBack->setGeometry(QRect(20, 20, 121, 51));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::WindowClose");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnBolusBack->setIcon(icon);
        btnBolusStart = new QPushButton(PageBolus);
        btnBolusStart->setObjectName(QString::fromUtf8("btnBolusStart"));
        btnBolusStart->setGeometry(QRect(620, 20, 121, 51));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("QIcon::ThemeIcon::DocumentSend");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        btnBolusStart->setIcon(icon1);
        txtBolusInstant = new QLineEdit(PageBolus);
        txtBolusInstant->setObjectName(QString::fromUtf8("txtBolusInstant"));
        txtBolusInstant->setGeometry(QRect(150, 60, 121, 71));
        QFont font6;
        font6.setPointSize(16);
        font6.setBold(true);
        font6.setWeight(75);
        txtBolusInstant->setFont(font6);
        label_81 = new QLabel(PageBolus);
        label_81->setObjectName(QString::fromUtf8("label_81"));
        label_81->setGeometry(QRect(150, 40, 131, 20));
        label_91 = new QLabel(PageBolus);
        label_91->setObjectName(QString::fromUtf8("label_91"));
        label_91->setGeometry(QRect(150, 130, 121, 20));
        btnScanGlucose = new QPushButton(PageBolus);
        btnScanGlucose->setObjectName(QString::fromUtf8("btnScanGlucose"));
        btnScanGlucose->setGeometry(QRect(360, 360, 221, 29));
        label_10 = new QLabel(PageBolus);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(360, 240, 221, 20));
        radUseInsulin = new QRadioButton(PageBolus);
        radUseInsulin->setObjectName(QString::fromUtf8("radUseInsulin"));
        radUseInsulin->setGeometry(QRect(110, 200, 141, 26));
        radUseInsulin->setChecked(false);
        radUseCarbs = new QRadioButton(PageBolus);
        radUseCarbs->setObjectName(QString::fromUtf8("radUseCarbs"));
        radUseCarbs->setGeometry(QRect(110, 230, 151, 26));
        btnBolusCalculate = new QPushButton(PageBolus);
        btnBolusCalculate->setObjectName(QString::fromUtf8("btnBolusCalculate"));
        btnBolusCalculate->setGeometry(QRect(110, 400, 591, 71));
        line = new QFrame(PageBolus);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(50, 150, 711, 31));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_14 = new QLabel(PageBolus);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(310, 40, 131, 20));
        txtBolusLongterm = new QLineEdit(PageBolus);
        txtBolusLongterm->setObjectName(QString::fromUtf8("txtBolusLongterm"));
        txtBolusLongterm->setGeometry(QRect(310, 60, 121, 71));
        txtBolusLongterm->setFont(font6);
        label_15 = new QLabel(PageBolus);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(310, 130, 121, 20));
        label_16 = new QLabel(PageBolus);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(480, 40, 131, 20));
        txtBolusRate = new QLineEdit(PageBolus);
        txtBolusRate->setObjectName(QString::fromUtf8("txtBolusRate"));
        txtBolusRate->setGeometry(QRect(480, 60, 121, 71));
        txtBolusRate->setFont(font6);
        label_17 = new QLabel(PageBolus);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(480, 130, 121, 20));
        radDeliveryImmediate = new QRadioButton(PageBolus);
        radDeliveryImmediate->setObjectName(QString::fromUtf8("radDeliveryImmediate"));
        radDeliveryImmediate->setGeometry(QRect(610, 210, 112, 26));
        radDeliveryImmediate->setChecked(true);
        radDeliveryExtended = new QRadioButton(PageBolus);
        radDeliveryExtended->setObjectName(QString::fromUtf8("radDeliveryExtended"));
        radDeliveryExtended->setGeometry(QRect(610, 240, 112, 26));
        label_18 = new QLabel(PageBolus);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(310, 170, 221, 20));
        label_25 = new QLabel(PageBolus);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(320, 10, 221, 20));
        stackedWidget->addWidget(PageBolus);
        PageOptions = new QWidget();
        PageOptions->setObjectName(QString::fromUtf8("PageOptions"));
        label_28 = new QLabel(PageOptions);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 0, 781, 81));
        QFont font7;
        font7.setPointSize(48);
        label_28->setFont(font7);
        btnOptionsProfiles = new QPushButton(PageOptions);
        btnOptionsProfiles->setObjectName(QString::fromUtf8("btnOptionsProfiles"));
        btnOptionsProfiles->setGeometry(QRect(170, 90, 461, 61));
        QFont font8;
        font8.setPointSize(26);
        btnOptionsProfiles->setFont(font8);
        btnOptionsProfiles->setFlat(false);
        btnOptionsHistory = new QPushButton(PageOptions);
        btnOptionsHistory->setObjectName(QString::fromUtf8("btnOptionsHistory"));
        btnOptionsHistory->setEnabled(false);
        btnOptionsHistory->setGeometry(QRect(170, 160, 461, 61));
        btnOptionsHistory->setFont(font8);
        btnOptionsHistory->setCheckable(false);
        btnOptionsHistory->setFlat(false);
        btnOptionsHome = new QPushButton(PageOptions);
        btnOptionsHome->setObjectName(QString::fromUtf8("btnOptionsHome"));
        btnOptionsHome->setGeometry(QRect(240, 400, 341, 61));
        btnOptionsHome->setFont(font8);
        btnOptionsHome->setFlat(false);
        stackedWidget->addWidget(PageOptions);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        label_8->setText(QCoreApplication::translate("MainWindow", "STATE: ", nullptr));
        btnOptions->setText(QCoreApplication::translate("MainWindow", "OPTIONS", nullptr));
        btnBolus->setText(QCoreApplication::translate("MainWindow", "BOLUS", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "STATUS: ", nullptr));
        Glucose_tracker->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "mmol/L", nullptr));
        ARROW->setText(QCoreApplication::translate("MainWindow", "ARROW", nullptr));
        iconLabel->setText(QString());
        STATE_OUTPUT->setText(QCoreApplication::translate("MainWindow", "Maintains", nullptr));
        EatFood->setText(QCoreApplication::translate("MainWindow", "Eat Food", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Increases Carbohydrate Glucose levels", nullptr));
        btnStopBolus->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        lblRemainingBolus->setText(QString());
        lblRemainingOnboard->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Battery:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Remaining:", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Insulin:", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Elapsed Simulation Time", nullptr));
        lblTime->setText(QCoreApplication::translate("MainWindow", "0:0", nullptr));
        lblFood->setText(QCoreApplication::translate("MainWindow", "Meal", nullptr));
        txtInsulinAmount->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Value", nullptr));
        txtGlucoseAmount->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Glucose", nullptr));
        btnBolusBack->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        btnBolusStart->setText(QCoreApplication::translate("MainWindow", "Start Bolus", nullptr));
        txtBolusInstant->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Value", nullptr));
        label_81->setText(QCoreApplication::translate("MainWindow", "Instant Dose:", nullptr));
        label_91->setText(QCoreApplication::translate("MainWindow", "Units", nullptr));
        btnScanGlucose->setText(QCoreApplication::translate("MainWindow", "Scan", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Glucose (mmol/L):", nullptr));
        radUseInsulin->setText(QCoreApplication::translate("MainWindow", "Insulin (units)", nullptr));
        radUseCarbs->setText(QCoreApplication::translate("MainWindow", "Carbs (grams)", nullptr));
        btnBolusCalculate->setText(QCoreApplication::translate("MainWindow", "Calculate", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Longterm Dose:", nullptr));
        txtBolusLongterm->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Value", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Units", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Delivery Rate:", nullptr));
        txtBolusRate->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Value", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Units/second", nullptr));
        radDeliveryImmediate->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        radDeliveryExtended->setText(QCoreApplication::translate("MainWindow", "Extended", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Calculate Dose", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Enter Dose", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Options", nullptr));
        btnOptionsProfiles->setText(QCoreApplication::translate("MainWindow", "Profiles", nullptr));
        btnOptionsHistory->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        btnOptionsHome->setText(QCoreApplication::translate("MainWindow", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

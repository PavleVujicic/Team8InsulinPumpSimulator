#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QTimer>
#include <QPixmap> //needed for icons states


#include "profilemanager.h"
#include "user.h"
#include "device.h"

QT_CHARTS_USE_NAMESPACE

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
    void on_createProfile_clicked();
    void createNewProfile();
    void addProfileToUI(const QString& name);
    void deleteSelectedProfile();
    void updateSelectedProfile();

    void on_updateProfile_clicked();

    void on_Start_clicked();

    void updateChartData();
    void setArrowDown();
    void setArrowUp();
    void setArrowRight();
    void updateDirection();
    void updateConditionIcon();
    void setIcon(const QString &filePath);
    void updateStateOutput();

    void on_EatFood_clicked();

    //Bolus/Basal stuff
    void onBolusClicked();
    void onBolusCancel();
    void onBolusCalculate();
    void onBolusStart();
    void onBolusScan();
    void onBolusStop();

    void basalDeposit();

    void onCtrlB();

private:
    Ui::MainWindow *ui;
	User *user;
    Device device;

    QButtonGroup* profileGroup;
    QChartView *chartView;  // Add this line for chart view
    QChart *chart;          // Chart object
    QLineSeries *series;    // Series object for the chart
    QTimer *updateTimer;
    QTimer *hourlyBasalTimer;

    QValueAxis *axisX;
    QValueAxis *axisY;
    int dataCount = 0;

    QLineSeries *constantLine3_9;
    QLineSeries *constantLine10;
    float lastGlucose;
};
#endif // MAINWINDOW_H

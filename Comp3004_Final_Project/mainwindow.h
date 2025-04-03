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


#include "profilemanager.h"
#include "user.h"
#include "device.h"

// QT_CHARTS_USE_NAMESPACE

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
    void update();
    void basalDeposit();

    void on_createProfile_clicked();
    void createNewProfile();
    void addProfileToUI(const QString& name);
    void deleteSelectedProfile();
    void updateSelectedProfile();

    void on_updateProfile_clicked();

    void on_Start_clicked();

    void updateChartData();
    void onBolusClicked();
    void onBolusCancel();
    void onBolusCalculate();
    void onBolusStart();
    void onBolusScan();
    void onBolusStop();

    void onCtrlB();

private:

    Ui::MainWindow *ui;
    // ProfileManager profileManager;
    QButtonGroup* profileGroup;
    User *user;
    Device device;

    QChartView *chartView;  // Add this line for chart view
    QChart *chart;          // Chart object
    QLineSeries *series;    // Series object for the chart
    QTimer *updateTimer;
    QTimer *hourlyBasalTimer;
    QValueAxis *axisX;
    QValueAxis *axisY;
    int dataCount = 0;
};
#endif // MAINWINDOW_H

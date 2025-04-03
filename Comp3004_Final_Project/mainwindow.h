#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRadioButton>
#include <QButtonGroup>
<<<<<<< HEAD
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QTimer>
#include <QPixmap> //needed for icons states


#include "profilemanager.h"
#include "User.h"

QT_CHARTS_USE_NAMESPACE
=======
#include "profilemanager.h"
>>>>>>> f2be3f35f87feabeb74f29cd0bbb95dd6da2b27e

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

<<<<<<< HEAD
    void updateChartData();
    void setArrowDown();
    void setArrowUp();
    void setArrowRight();
    void updateDirection();
    void updateConditionIcon();
    void setIcon(const QString &filePath);
    void updateStateOutput();

    void on_EatFood_clicked();

=======
>>>>>>> f2be3f35f87feabeb74f29cd0bbb95dd6da2b27e
private:
    Ui::MainWindow *ui;
    ProfileManager profileManager;
    QButtonGroup* profileGroup;
<<<<<<< HEAD
    QChartView *chartView;  // Add this line for chart view
    QChart *chart;          // Chart object
    QLineSeries *series;    // Series object for the chart
    User *user;
    QTimer *updateTimer;
    QValueAxis *axisX;
    QValueAxis *axisY;
    int dataCount = 0;

    QLineSeries *constantLine3_9;
    QLineSeries *constantLine10;
    float lastGlucose;
=======
>>>>>>> f2be3f35f87feabeb74f29cd0bbb95dd6da2b27e
};
#endif // MAINWINDOW_H

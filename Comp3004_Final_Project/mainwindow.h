#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRadioButton>
#include <QButtonGroup>
#include "profilemanager.h"

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

private:
    Ui::MainWindow *ui;
    ProfileManager profileManager;
    QButtonGroup* profileGroup;
};
#endif // MAINWINDOW_H

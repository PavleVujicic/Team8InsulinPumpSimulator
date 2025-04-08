#include "device.h"
#include <iostream>

#include <QApplication>
#include <QMessageBox>


Device::Device(){
    // CAN CHANGE
    batteryConsumptionRate = 0.125f;    // default: 0.125 (~13 minute lifetime)
    insulinOnBoard = 200.0f;            // default: 200
    insulinLowThreshhold = 20.0f;       // default: 20
    warnInterval = 30;                  // default: 30
    emergencyAmountInstant = 0.5f;     // default: 1
    emergencyAmountLongterm = 1.0f;     // default: 1.5
    emergencyAmountRate = 0.25f;        // default: 0.25


    // KEEP HARDCODED (unless testing)
    batteryPercent = 100.0f;    // default: 100
    bolusBuffer = 0.0f;         // default: 0
    bolusTransferRate = 0.5f;   // default: 0.5
    insulinWarn = 0;            // default: 0
}

void Device::decreaseBattery()
{
    batteryPercent -= batteryConsumptionRate;
    if (batteryPercent < 25 && !batteryWarned) {
        batteryWarned = true;
        QMessageBox batteryWarnBox;
        batteryWarnBox.setText("Battery below 25%. Please charge");
        batteryWarnBox.setInformativeText("Press OK to add 30%.");
        batteryWarnBox.setStandardButtons(QMessageBox::Ignore | QMessageBox::Ok);
        switch (batteryWarnBox.exec()) {
        case QMessageBox::Ignore:
            break;

        case QMessageBox::Ok:
            batteryPercent += 30;
            break;

        default:
            // should not be reached
            break;
        }
    }
    if (batteryPercent == 0) {
        QMessageBox batteryWarnBox;
        batteryWarnBox.setText("Uh Oh! No more battery :( BYE BYE");
        batteryWarnBox.setInformativeText("Critical Error: Device out of power. Triggering shutdown sequence. Saving information to log.txt");
        // TODO: actually make it save crash data.
        batteryWarnBox.exec();
        QApplication::quit();
    }
    if (batteryPercent > 25) batteryWarned = false;
}

bool Device::startBolusPlan(float immediateInsulin, float longtermInsulin, float bolusTransfer)
{
    float diff = insulinOnBoard - (immediateInsulin + longtermInsulin);
    if (diff < 0) return false; // Not enough insulin
    insulinOnBoard = diff;

    user->applyInsulin(immediateInsulin);

    bolusBuffer = longtermInsulin;
    bolusTransferRate = bolusTransfer;

    historyManager.addInsulinUse(step, immediateInsulin + longtermInsulin);
    return true;
}

void Device::tickBolus()
{
    if (bolusBuffer >= bolusTransferRate) {
        bolusBuffer -= bolusTransferRate;
        user->applyInsulin(bolusTransferRate);
    } else {
        user->applyInsulin(bolusBuffer);
        bolusBuffer = 0;
    }
}

void Device::tick()
{
    historyManager.addDataPoint(++step, user->getCurrentGlucoseLevel());
    if (bolusBuffer > 0) tickBolus();
    decreaseBattery();
    checkInsulinLevel();
    checkEmergencyBolus();
}

void Device::checkInsulinLevel()
{
    if (insulinWarn > 0) {
        insulinWarn--;
        return;
    }
    if (insulinWarn == 0 && insulinOnBoard < insulinLowThreshhold) {
        insulinWarn = warnInterval;
        QMessageBox insulinWarnBox;
        insulinWarnBox.setText("Insulin running low");
        insulinWarnBox.setInformativeText("Press OK to add 50 units.");
        insulinWarnBox.setStandardButtons(QMessageBox::Ignore | QMessageBox::Ok);
        switch (insulinWarnBox.exec()) {
        case QMessageBox::Ignore:
            break;

        case QMessageBox::Ok:
            insulinOnBoard += 50;
            break;

        default:
            // should not be reached
            break;
        }
    }
}

void Device::checkEmergencyBolus()
{
    if (user->getCurrentGlucoseLevel() > 10.0f) {
        if (bolusBuffer > 0) return;
        QMessageBox bolusWarnBox;
        bolusWarnBox.setText("Warning! Glucose levels dangerously high!");
        bolusWarnBox.setInformativeText("Administering emergency bolus");
        bolusWarnBox.exec();

        bool ok = startBolusPlan(emergencyAmountInstant, emergencyAmountLongterm, emergencyAmountRate);
        if (!ok) {
            QMessageBox bolusWarnBox;
            bolusWarnBox.setText("Could not administer emergency bolus!");
            bolusWarnBox.setInformativeText("Please resolve machine issue immediately.");
            bolusWarnBox.exec();
        }
    }
}

void Device::cancel()
{
    insulinOnBoard += bolusBuffer;
    bolusBuffer = 0;
}

void Device::simulateBasal(){
    if(selectedProfile==nullptr){
        return;
    }
    float basalRate = selectedProfile->basalRate;

    if (user->getCurrentGlucoseLevel() < 3.9) basalRate = 0;
    else if (user->getCurrentGlucoseLevel() < 6.25) basalRate *= 0.5;
    else if (user->getCurrentGlucoseLevel() > 8.9) basalRate *= 2.0;

    if (insulinOnBoard<basalRate){
        checkInsulinLevel();
    }
    std::cout<<"Deposit hourly basal: "<<basalRate<<" units"<<std::endl;
    insulinOnBoard-=basalRate;
    user->applyInsulin(basalRate);
    historyManager.addInsulinUse(step, basalRate);
    //float effectOnGlucose = user->calculateInsulinEffect(basalRate);
}

void Device::setUser(User *u){user = u;}

void Device::setSelectedProfile(Profile* p){
    std::cout << "Current Profile: " << p->name << std::endl;
    selectedProfile = p;
}

#include "device.h"

#include <QApplication>
#include <QMessageBox>

Device::Device() {
    // CAN CHANGE
    batteryConsumptionRate = 0.125f;    // default: 0.125 (~13 minute lifetime)
    insulinOnBoard = 200.0f;            // default: 200

    // KEEP HARDCODED (unless testing)
    batteryPercent = 100.0f;    // default: 100
    bolusBuffer = 0.0f;         // default: 0
    bolusTransferRate = 0.5f;   // default: 0.5
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

    // TODO: send immediateInsulin to user
    bolusBuffer = longtermInsulin;
    bolusTransferRate = bolusTransfer;
    return true;
}

void Device::tickBolus()
{
    if (bolusBuffer >= bolusTransferRate) {
        bolusBuffer -= bolusTransferRate;
        // TODO: send bolusTransferRate to user;
    } else {
        // TODO: send bolusBuffer to user;
        bolusBuffer = 0;
    }
}

void Device::tick()
{
    if (bolusBuffer > 0) tickBolus();
    decreaseBattery();
}

void Device::cancel()
{
    insulinOnBoard += bolusBuffer;
    bolusBuffer = 0;
}

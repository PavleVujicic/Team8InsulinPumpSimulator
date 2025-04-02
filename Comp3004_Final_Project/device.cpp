#include "device.h"

Device::Device() {
    // CAN CHANGE
    batteryConsumptionRate = 0.125;
    insulinOnBoard = 200.0f;

    // KEEP HARDCODED (unless testing)
    batteryPercent = 100.0f;    // default: 100
    bolusBuffer = 0.0f;         // default: 0
    bolusTransferRate = 0.5f;   // default: 0.5f
}

void Device::decreaseBattery()
{
    batteryPercent -= batteryConsumptionRate;
}

bool Device::startBolusPlan(float immediateInsulin, float longtermInsulin, float bolusTransfer)
{
    float diff = insulinOnBoard - (immediateInsulin + longtermInsulin);
    if (diff < 0) return false; // Not enough insulin
    insulinOnBoard = diff;

    // TODO: send immediateInsulin to user
    bolusBuffer = longtermInsulin;
    bolusTransferRate = bolusTransfer;
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
    tickBolus();
    decreaseBattery();
}

#ifndef DEVICE_H
#define DEVICE_H

#include "user.h"
#include "profilemanager.h"
#include "historymanager.h"
class Device {
public:
    Device();

    /** decreaseBattery
     *
     *  Lowers batteryPercent by batteryConsumptionRate and returns new batteryPercent.
     *  To be called every second
     */
    void decreaseBattery();

    /** startBolusPlan
     *
     *  Starts a bolus plan.
     *  Checks if enough insulin is on board. Returns false if not. If enough, continue
     *  Removes immediateInsulin+longtermInsulin from insulinOnBoard
     *  Adds immediateInsulin to user.
     *    Adds longtermInsulin to bolusBuffer.
     *  Sets bolusTransferRate to bolusTransfer
     *  Return true
     */
    bool startBolusPlan(float immediateInsulin, float longtermInsulin, float bolusTransfer);

    /**
     *  Subtracts bolusTransferRate from bolusBuffer
     *  Adds bolusTransferRate to user;
     *  (Check for if bolusBuffer-bolusTransferRate < 0)
     *    To be called every second
     */
    void tickBolus();

    /**
     *  Call this every second. Calls decreaseBattery and tickBolus
     */
    void tick();

    void checkInsulinLevel();

    void checkEmergencyBolus();

    void cancel();

    inline void addBattery(float i) { batteryPercent += i; }
    inline float getInsulinOnBoard() const { return insulinOnBoard; }
    inline float getBatteryPercent() const { return batteryPercent; }
    inline float getBolusBuffer() const { return bolusBuffer; }
    inline float isBolusBufferClear() const { return bolusBuffer == 0; }

    inline Profile* getSelectedProfile() const { return selectedProfile; }

    void simulateBasal();
    void setUser(User*);
    void setSelectedProfile(Profile*);

    inline HistoryManager::Data getData(int range) { return historyManager.getData(range); }
private:
    User* user;
    Profile* selectedProfile;
    HistoryManager historyManager;

    bool batteryWarned = false;
    int insulinWarn;
    int warnInterval;

    float insulinLowThreshhold;
    float insulinOnBoard;
    float batteryConsumptionRate;
    float batteryPercent;
    float bolusBuffer;
    float bolusTransferRate;

    float emergencyAmountInstant;
    float emergencyAmountLongterm;
    float emergencyAmountRate;
    float basalRate;

    int step = 0;
};

#endif // DEVICE_H

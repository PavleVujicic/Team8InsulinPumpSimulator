#ifndef USER_H
#define USER_H

#include <QString>
#include <QVector>
#include <QDateTime>


#include "profilemanager.h"

class User {
public:
    User();

    inline float getCurrentGlucoseLevel() const { return currentGlucose; }
    void simulateGlucose();
    void applyInsulin(float units);     // Affects future glucose levels
    float calculateInsulinEffect(float units);
    QVector<float> getGlucoseHistory() const;
    QVector<float> getGlucoseHistoryTail() const;

    ProfileManager* getProfileManager() const;

    void setIncrease();
    void setDecrease();

private:
    ProfileManager* profileManager;
    float currentGlucose;  // in mmol/L
    QVector<float> glucoseHistory;

    float insulinSensitivity;  // how much 1 unit of insulin lowers BG
    float carbImpactFactor;    // how much 1g of carbs raises BG



    QDateTime lastUpdated;

    bool increase;
    bool decrease;

    void updateGlucoseTrend(); // internal update
};

#endif //USER_H

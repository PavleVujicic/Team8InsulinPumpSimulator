#ifndef USER_H
#define USER_H

#include <QString>
#include <QVector>
#include <QDateTime>
#include "profilemanager.h"

class User {
public:
    User();

    float getCurrentGlucoseLevel() const;
    void simulateGlucose();
    void applyInsulin(float units);     // Affects future glucose levels

    QVector<float> getGlucoseHistory() const;
    QVector<float> getGlucoseHistoryTail() const;
    ProfileManager* getProfileManager() const;
    bool foodConsumed = false;
    float foodMult = 1;

    void setIncrease();
    void setDecrease();
    void eatFood(int amount = 1);

private:
    ProfileManager* profileManager;
    float currentGlucose;  // in mmol/L
    QVector<float> glucoseHistory;

    float insulinSensitivity;  // how much 1 unit of insulin lowers BG
    float carbImpactFactor;    // how much 1g of carbs raises BG
    int carbsConsumed;
    float activeInsulin = 0;
    float glucoseLossPerInsulin = 4.0f;

    QDateTime lastUpdated;

    bool increase;
    bool decrease;

    void updateGlucoseTrend(); // internal update
};

#endif //USER_H

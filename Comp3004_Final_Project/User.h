//
// Created by akil on 3/29/25.
//

#ifndef USER_H
#define USER_H

#include <QString>
#include <QVector>
#include <QDateTime>


class ProfileManager;

class User {
public:
    User();

    float getCurrentGlucoseLevel() const;
    void simulateGlucose();
    void applyInsulin(float units);     // Affects future glucose levels

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

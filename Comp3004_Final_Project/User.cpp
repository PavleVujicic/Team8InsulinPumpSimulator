//
// Created by akil on 3/31/25.
//


#include "User.h"
#include <QtMath>
#include <QRandomGenerator>

User::User()
    : currentGlucose(6.0f),  // Normal level to start
      insulinSensitivity(0.8f),
      carbImpactFactor(0.1f),
      lastUpdated(QDateTime::currentDateTime()) {
    for (int i = 0; i < 30; i++) glucoseHistory.append(currentGlucose); // generate starting values
}

void User::simulateGlucose() {
    float change;


    if (increase) {
        change = static_cast<float>(QRandomGenerator::global()->bounded(0, 501)) / 1000.0f; // Range [0.0, 0.5]
    } else if (decrease) {
        change = static_cast<float>(QRandomGenerator::global()->bounded(-500, 1)) / 1000.0f; // Range [-0.5, 0.0]
    } else {
        change = static_cast<float>(QRandomGenerator::global()->bounded(-500, 501)) / 1000.0f; // Range [-0.5, 0.5]
    }

    currentGlucose += change;
    currentGlucose = qMax(3.5f, qMin(15.0f, currentGlucose)); // clamp
    glucoseHistory.append(currentGlucose);
    lastUpdated = QDateTime::currentDateTime();
}

void User::applyInsulin(float units) {
    float drop = units * insulinSensitivity;
    currentGlucose -= drop;
    currentGlucose = qMax(currentGlucose, 2.5f); // avoid crashing
    glucoseHistory.append(currentGlucose);
}

QVector<float> User::getGlucoseHistory() const{return glucoseHistory;}

QVector<float> User::getGlucoseHistoryTail() const {
    QVector<float> glucoseHistoryTail;

    int historySize = glucoseHistory.size();

    if (historySize < 30) {
        glucoseHistoryTail = glucoseHistory;
        while (glucoseHistoryTail.size() < 30) {
            glucoseHistoryTail.append(0.0f);
        }
    } else {
        for (int i = historySize - 30; i < historySize; ++i) {
            glucoseHistoryTail.append(glucoseHistory[i]);
        }
    }

    return glucoseHistoryTail;
}

ProfileManager* User::getProfileManager() const {
    return profileManager;
}

void User::setIncrease(){
    if(decrease){decrease = false;}
    increase = true;
}

void User::setDecrease(){
    if(increase){increase = false;}
    decrease = true;
}

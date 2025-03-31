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
      lastUpdated(QDateTime::currentDateTime()) {}

void User::simulateGlucose() {
    float change;

    if(increase){
        change = QRandomGenerator::global()->bounded(0.0f, 0.5f);
    }else-if(decrease){
        change = QRandomGenerator::global()->bounded(-0.5f, 0.0f);
    }else{
        change = QRandomGenerator::global()->bounded(-0.5f, 0.5f);
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
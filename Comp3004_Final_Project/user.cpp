//
// Created by akil on 3/31/25.
//


#include "user.h"
#include <QtMath>
#include <QRandomGenerator>
#include <QDebug>


User::User()
    : currentGlucose(6.0f),  // Normal level to start
      insulinSensitivity(0.8f),
      carbImpactFactor(6.0f), // Assuming a default CIF of 6g per 1 mmol/L:
      lastUpdated(QDateTime::currentDateTime()) {
    profileManager = new ProfileManager();
    carbsConsumed = 0;
    for (int i = 0; i < 30; i++) glucoseHistory.append(currentGlucose); // generate starting values
}

void User::simulateGlucose() {
    float change;

    // Simulate digestion: gradual glucose increase
    if (digestionTimeRemaining > 0) {
        currentGlucose += glucosePerSecond;
        digestionTimeRemaining--;

        if (digestionTimeRemaining == 0) {
            foodConsumed = false; // digestion finished
        }
    }

    // Handle random fluctuations in glucose
    if (increase) {
        change = static_cast<float>(QRandomGenerator::global()->bounded(0, 201)) / 1000.0f; // Range [0.0, 0.2]
    } else if (decrease) {
        change = static_cast<float>(QRandomGenerator::global()->bounded(-200, 0)) / 1000.0f; // Range [-0.2, 0.0]
    } else {
        change = static_cast<float>(QRandomGenerator::global()->bounded(-200, 201)) / 1000.0f; // Range [-0.3, 0.3]
    }

    currentGlucose += change;

    if (activeInsulin > 0) {
        if (activeInsulin < insulinSensitivity) {
            currentGlucose -= activeInsulin;
            activeInsulin = 0;
        } else {
            currentGlucose -= insulinSensitivity;
            activeInsulin -= insulinSensitivity;
        }
    }
    // qDebug() << activeInsulin;
    currentGlucose = qMax(0.5f, qMin(12.0f, currentGlucose)); // clamp
    glucoseHistory.append(currentGlucose);
    lastUpdated = QDateTime::currentDateTime();
}

void User::applyInsulin(float units) {
    activeInsulin += units * glucoseLossPerInsulin;
    // float drop = units * insulinSensitivity;
    // currentGlucose -= drop;
    // currentGlucose = qMax(currentGlucose, 2.5f); // avoid crashing
    // glucoseHistory.append(currentGlucose);
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

float User::getCurrentGlucoseLevel() const {
    return currentGlucose;
}

void User::eatFood(int amount) {
    foodConsumed = true;

    carbsConsumed = QRandomGenerator::global()->bounded(10, 21); // 10 to 20 grams
    glucoseToAdd = carbsConsumed / carbImpactFactor;

    digestionTimeRemaining = 10; // spread over 10 seconds
    glucosePerSecond = glucoseToAdd / static_cast<float>(digestionTimeRemaining);

    switch (amount) {
    case 1:
        foodMult = 0.5f;
        break;
    case 3:
        foodMult = 2.0f;
        break;
    default:
        foodMult = 1.0f;
        break;
    }
    qDebug() << foodMult;
}

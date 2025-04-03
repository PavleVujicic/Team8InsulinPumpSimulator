//
// Created by akil on 3/31/25.
//


#include "User.h"
#include <QtMath>
#include <QRandomGenerator>

User::User()
    : currentGlucose(6.0f),  // Normal level to start
      insulinSensitivity(0.8f),
      carbImpactFactor(5.0f), // Assuming a default CIF of 5g per 1 mmol/L:
      lastUpdated(QDateTime::currentDateTime()) {}

void User::simulateGlucose() {
    carbsConsumed = QRandomGenerator::global()->bounded(10, 21); // Generate a random value between 10 and 20 for carbsConsumed
    float change;

    // Check if food was consumed, and increase glucose accordingly
    if (foodConsumed) {
        float glucoseIncrease = carbsConsumed / carbImpactFactor;  // Formula for glucose increase
        currentGlucose += glucoseIncrease;  // Add glucose increase
        foodConsumed = false;  // Reset foodConsumed flag after processing
    }

    // Handle random fluctuations in glucose
    if (increase) {
        change = static_cast<float>(QRandomGenerator::global()->bounded(0, 201)) / 1000.0f; // Range [0.0, 0.2]
    } else if (decrease) {
        change = static_cast<float>(QRandomGenerator::global()->bounded(-200, 1)) / 1000.0f; // Range [-0.2, 0.0]
    } else {
        change = static_cast<float>(QRandomGenerator::global()->bounded(-200, 201)) / 1000.0f; // Range [-0.2, 0.2]
    }

    currentGlucose += change;
    currentGlucose = qMax(3.5f, qMin(12.0f, currentGlucose)); // clamp
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

float User::getCurrentGlucoseLevel() const {
    return currentGlucose;
}

void User::eatFood() {
    foodConsumed = true;
}


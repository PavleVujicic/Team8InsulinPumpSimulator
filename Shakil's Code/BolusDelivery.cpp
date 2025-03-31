//
// Created by akil on 3/31/25.
//

#include "BolusDelivery.h"
#include <QDebug>

BolusDelivery::BolusDelivery(const Profile* profile)
    : profile(profile), calculator(*profile) {}

BolusResult BolusDelivery::calculateBolus(float glucose, float carbs,
                                          float duration, float immediateFraction) {
    return calculator.calculateBolus(glucose, carbs, duration, immediateFraction);
}

void BolusDelivery::deliverBolus(const BolusResult& result) {
    qDebug() << "[BolusDelivery] Immediate bolus:" << result.immediateBolus << "units.";

    if (result.extendedBolus > 0.0f) {
        qDebug() << "[BolusDelivery] Scheduled extended bolus:"
                 << result.extendedBolus << "units over"
                 << result.extendedBolusPerHour << "units/hour.";
        // You can schedule per-hour application via QTimer or InsulinDeliveryController
    }

    // Apply immediate bolus effect to user glucose here if needed
    // user->applyInsulin(result.immediateBolus);  // if user is passed in
}

void BolusDelivery::setOverrideBolus(float overrideValue) {
    calculator.overrideBolus(overrideValue);
}

float BolusDelivery::getOverrideBolus() const {
    return calculator.getLastBolus();
}

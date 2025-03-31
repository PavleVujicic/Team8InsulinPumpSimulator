//
// Created by akil on 3/31/25.
//

#include "BolusCalculator.h"
#include <QGlobal>

BolusCalculator::BolusCalculator(const Profile& profile)
    : profile(profile), lastBolus(0.0f), overriddenBolus(-1.0f) {}

BolusResult BolusCalculator::calculateBolus(float glucose, float carbs,
                                            float extendedDuration, float immediateFraction) {
    BolusResult result;

    // 1. Carb Bolus
    float carbBolus = carbs / profile.carbRatio;

    // 2. Correction Bolus
    float correctionBolus = 0.0f;
    if (glucose > profile.targetGlucose) {
        correctionBolus = (glucose - profile.targetGlucose) / profile.correctionFactor;
    }

    // 3. Total before IOB
    result.totalBolusBeforeIOB = carbBolus + correctionBolus;

    // 4. Adjust for IOB
    result.finalBolus = result.totalBolusBeforeIOB - IOB;
    result.finalBolus = qMax(0.0f, result.finalBolus);

    // 5. Override if set
    if (overriddenBolus >= 0.0f) {
        result.finalBolus = overriddenBolus;
    }

    // 6. Split Bolus
    if (extendedDuration > 0.0f && immediateFraction < 1.0f) {
        result.immediateBolus = result.finalBolus * immediateFraction;
        result.extendedBolus = result.finalBolus * (1.0f - immediateFraction);
        result.extendedBolusPerHour = result.extendedBolus / extendedDuration;
    } else {
        result.immediateBolus = result.finalBolus;
    }

    lastBolus = result.finalBolus;
    return result;
}

void BolusCalculator::overrideBolus(float value) {
    overriddenBolus = value;
}

float BolusCalculator::getLastBolus() const {
    return lastBolus;
}

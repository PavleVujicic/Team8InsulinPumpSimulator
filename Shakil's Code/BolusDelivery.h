//
// Created by akil on 3/29/25.
//

#ifndef BOLUSDELIVERY_H
#define BOLUSDELIVERY_H

#include "ProfileManager.h"
#include "BolusCalculator.h"
#include "BolusResult.h"

class BolusDelivery{
public:
    BolusDelivery(const Profile* profile);

    BolusResult calculateBolus(float glucose, float carbs,
                                float duration = 0.0f, float immediateFraction = 1.0f);

    void deliverBolus(const BolusResult& result);
    void setOverrideBolus(float overrideValue);
    float getOverrideBolus() const;

private:
    const Profile* profile;
    BolusCalculator calculator;
};
#endif //BOLUSDELIVERY_H

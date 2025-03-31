//
// Created by akil on 3/31/25.
//

#ifndef BOLUSCALCULATOR_H
#define BOLUSCALCULATOR_H


struct BolusResult {
    float totalBolusBeforeIOB = 0.0f;
    float finalBolus = 0.0f;
    float immediateBolus = 0.0f;
    float extendedBolus = 0.0f;
    float extendedBolusPerHour = 0.0f;
};

class BolusCalculator {
public:
    BolusCalculator(const Profile& profile);

    //include in gui inputs for carbs to represent meals
    //hardcode insulin on board
    BolusResult calculateBolus(float glucose, float carbs,
                                float extendedDuration = 0.0f, float immediateFraction = 1.0f);

    void overrideBolus(float value);
    float getLastBolus() const;

private:
    Profile profile;
    float IOB = 10.0f;
    float lastBolus;
    float overriddenBolus;
};



#endif //BOLUSCALCULATOR_H

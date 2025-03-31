#ifndef PROFILE_MANAGER_H
#define PROFILE_MANAGER_H

#include <vector>
#include <string>
#include <utility>

struct Profile {
    std::string name;
    double basalRate;
    double carbRatio;
    double correctionFactor;
    int pin;

    Profile(const std::string& name, double basal, double carb, double correction, int pin)
        : name(name), basalRate(basal), carbRatio(carb), correctionFactor(correction), pin(pin) {}
};

class ProfileManager {
private:
    std::vector<Profile> profiles;

public:
    void createProfile(const std::string& name, double basal, double carb, double correction, int pin);
    std::vector<std::string> getProfileNames() const;
    Profile* getProfile(const std::string& name);
    bool updateProfile(const std::string& oldName, double basalRate, double carbRatio, double correctionFactor, int pin, const std::string& newName);
    bool deleteProfile(const std::string& name);
    void listProfiles() const;
};

#endif // PROFILE_MANAGER_H
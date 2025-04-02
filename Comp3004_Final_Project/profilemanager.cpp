#include "profilemanager.h"
#include <iostream>

ProfileManager::ProfileManager(){}

void ProfileManager::createProfile(const std::string& name, double basal, double carb, double correction, int pin) {
    profiles.push_back(Profile(name, basal, carb, correction, pin));
}

std::vector<std::string> ProfileManager::getProfileNames() const {
    std::vector<std::string> names;
    for (const auto& profile : profiles) {
        names.push_back(profile.name);
    }
    return names;
}

Profile* ProfileManager::getProfile(const std::string& name) {
    for (auto& profile : profiles) {
        if (profile.name == name) {
            return &profile;
        }
    }
    return nullptr;  // Profile not found
}

bool ProfileManager::updateProfile(const std::string& oldName, double basalRate, double carbRatio, double correctionFactor, int pin, const std::string& newName) {
    for (auto& profile : profiles) {
        if (profile.name == oldName) {  // Find the profile by its old name
            // If the name is changing, check if the new name already exists
            if (oldName != newName) {
                for (const auto& existingProfile : profiles) {
                    if (existingProfile.name == newName) {
                        return false; // Name conflict, another profile already has this name
                    }
                }
            }

            // Update profile details
            profile.name = newName;
            profile.basalRate = basalRate;
            profile.carbRatio = carbRatio;
            profile.correctionFactor = correctionFactor;
            profile.pin = pin;

            return true;  // Profile updated successfully
        }
    }
    return false; // Profile not found
}


bool ProfileManager::deleteProfile(const std::string& name) {
    for (auto it = profiles.begin(); it != profiles.end(); ++it) {
        if (it->name == name) {
            profiles.erase(it);
            return true;
        }
    }
    return false;  // Profile not found
}

void ProfileManager::listProfiles() const {
    for (const auto& profile : profiles) {
        std::cout << "\nProfile: " << profile.name << std::endl;
        std::cout << "Profile: " << profile.basalRate << std::endl;
        std::cout << "Profile: " << profile.carbRatio << std::endl;
        std::cout << "Profile: " << profile.correctionFactor << std::endl;
        std::cout << "Profile: " << profile.pin << std::endl;
    }
}

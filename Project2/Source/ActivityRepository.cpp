#include "ActivityRepository.hpp"

Activity* ActivityRepository::findByLocation(std::string locationName) {
    for (int i = 0; i < mEntities.size(); i++) {
        if (mEntities[i]->getLocation() == locationName)
            return mEntities[i];
    }
    throw std::runtime_error("Room with this activity does not exists!");
}

Activity* ActivityRepository::findByDescription(std::string description) {
    for (int i = 0; i < mEntities.size(); i++) {
        if (mEntities[i]->getDescription() == description)
            return mEntities[i];
    }
    throw std::runtime_error("Room with this activity does not exists!");
}

std::vector<Activity*> ActivityRepository::searchByOwner(std::string ownerName) {
    std::vector<Activity*> activities;
    for(int i = 0; i < mEntities.size(); i++) {
        if (mEntities[i]->getOwner() == ownerName)
            activities.push_back(mEntities[i]);
    }
    if (activities.size() != 0)
        return activities;
    throw std::runtime_error("Activities with this person could not be found!");
}

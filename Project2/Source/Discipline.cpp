//
//  Discipline.cpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#include "Discipline.h"
#include "StudentRole.h"

Discipline::Discipline(std::string name, Activity* activity) {
    this->mName = name;
    this->mActivities.push_back(activity);
}

Discipline::Discipline(std::string name, std::vector<Activity*> activities) {
    this->mName = name;
    this->mActivities = activities;
}

std::string Discipline::getName() {
    return mName;
}

Activity* Discipline::getActivity(std::string name) {
    for (int i = 0; i < mActivities.size(); i++) {
        if (mActivities[i]->getDescription() == name)
            return mActivities[i];
    }
    throw std::runtime_error("Activity does not exist!");
}

std::vector<Activity*> Discipline::getActivities() {
    return mActivities;
}

void Discipline::setName(std::string name) {
    this->mName = name;
}

void Discipline::setActivities(std::vector<Activity *> activities) {
    this->mActivities = activities;
}

void Discipline::addActivity(Activity* activity) {
    this->mActivities.push_back(activity);
}

void Discipline::addActivities(std::vector<Activity*> activities) {
    this->mActivities = activities;
}

void Discipline::removeActivity(std::string name) {
    std::vector<Activity*>::iterator it;
    bool valide = false;
    for (it = mActivities.begin(); it != mActivities.end(); it++) {
        if ((*it)->getDescription() == name) {
            mActivities.erase(it);
            valide = true;
            break;
        }
    }
    if(!valide)
        throw std::runtime_error("Activity does not exist!");
}

void Discipline::addParticipant(Person* person) {
    this->mParticipants.push_back(person);
    StudentRole* student = NULL;
    try {
        student = dynamic_cast<StudentRole*>(person->displayRole(1));
    } catch (std::runtime_error const e) {}
    if (student != NULL)
        student->addMark(NULL, this);
}

void Discipline::removeParticipantByCnp(int CNP) {
    std::vector<Person*>::iterator it;
    bool valide = false;
    for (it = mParticipants.begin(); it != mParticipants.end(); it++) {
        if ((*it)->getCNP() == CNP) {
            mParticipants.erase(it);
            valide = true;
            break;
        }
    }
    if (!valide)
        throw std::runtime_error("Person could not be found");
}

void Discipline::removeByFullName(std::string firstName, std::string lastName) {
    std::vector<Person*>::iterator it;
    bool valide = false;
    for (it = mParticipants.begin(); it != mParticipants.end(); it++) {
        if ((*it)->getLastName() == lastName && (*it)->getFirstName() == firstName) {
            mParticipants.erase(it);
            valide = true;
            break;
        }
    }
    if (!valide)
        throw std::runtime_error("Person could not be found");
}

long Discipline::getSizeActivities() {
    return mActivities.size();
}

long Discipline::getSizeParticipants() {
    return mParticipants.size();
}



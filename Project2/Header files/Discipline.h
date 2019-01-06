//
//  Discipline.h
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef Discipline_h
#define Discipline_h

#include "Activity.h"

class Discipline {
public:
    Discipline(std::string name, Activity* activity);
    Discipline(std::string name, std::vector<Activity*> activities);
    std::string getName();
    Activity* getActivity(std::string name);
    std::vector<Activity*> getActivities();
    void setName(std::string name);
    void setActivities(std::vector<Activity*> activities);
    void addActivity(Activity* activity);
    void addActivities(std::vector<Activity*> activities);
    void removeActivity(std::string name);
    void addParticipant(Person* person);
    void removeParticipantByCnp(int CNP);
    void removeByFullName(std::string firstName, std::string lastName);
    long getSizeActivities();
    long getSizeParticipants();
private:
    std::string mName;
    std::vector<Activity*> mActivities;
    std::vector<Person*> mParticipants;
};

#endif /* Discipline_h */

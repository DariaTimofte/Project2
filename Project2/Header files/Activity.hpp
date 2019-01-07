#ifndef Activity_h
#define Activity_h


#include<iostream>
#include "Room.hpp"
#include "Person.hpp"

class Activity
{
public:
    Activity() {}
    Activity(Room* location, Person* owner, std::string description);
    std::string getLocation();
    std::string getOwner();
    std::string getDescription();
    void setLocation(Room* room);
    void setOwner(Person* owner);
    void setDescription(std::string description);
protected:
	Room* mLocation;
	Person* mOwner;
    std::string mDescription;
};

#endif /*  Activity_h */


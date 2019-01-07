#ifndef ActivityRepository_h
#define ActivityRepository_h

#include "Repository.hpp"
#include "Activity.hpp"
#include <vector>

class ActivityRepository: public Repository<Activity> {
public:
    Activity* findByLocation(std::string locationName);
    Activity* findByDescription(std::string description);
    std::vector<Activity*> searchByOwner(std::string ownerName);
};

#endif /*  ActivityRepository_h */


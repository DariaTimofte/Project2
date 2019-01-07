//
//  GuestRole.h
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef GuestRole_h
#define GuestRole_h

#include <iostream>
#include "Role.hpp"
#include "Activity.hpp"
#include <vector>

class GuestRole:public Role {
public:
    GuestRole();
    GuestRole(std::vector<Activity*> activities);
    GuestRole(Activity* activity);
private:
    std::vector<Activity*> mActivities;
};

#endif /* GuestRole_h */

//
//  GuestRole.cpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#include "GuestRole.hpp"

GuestRole::GuestRole()
:Role(Role::GUEST_ROLE)
{}

GuestRole::GuestRole(std::vector<Activity*> activities)
:Role(Role::GUEST_ROLE)
{
    this->mActivities = activities;
}

GuestRole::GuestRole(Activity* activity)
:Role(Role::GUEST_ROLE)
{
    this->mActivities.push_back(activity);
}

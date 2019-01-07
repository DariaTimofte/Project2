//
//  AdministrativeRole.cpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#include "AdministrativeRole.hpp"
#include "Role.hpp"

AdministrativeRole::AdministrativeRole()
:Role(Role::ADMINISTRATIVE_ROLE)
{}

AdministrativeRole::AdministrativeRole(std::vector<Room*> rooms)
:Role(Role::ADMINISTRATIVE_ROLE)
{
    this->mRoomsAdministered = rooms;
}

AdministrativeRole::AdministrativeRole(Room* room)
:Role(Role::ADMINISTRATIVE_ROLE)
{
    this->mRoomsAdministered.push_back(room);
}

Room* AdministrativeRole::getRoom(std::string name) {
    std::vector<Room*>::iterator it;
    for (it = mRoomsAdministered.begin(); it != mRoomsAdministered.end(); it++) {
        if ((*it)->get_Name() == name)
            return *it;
    }
    throw std::runtime_error("Room not found!");
}

std::vector<Room*> AdministrativeRole::getAllRooms() {
    return this->mRoomsAdministered;
}

void AdministrativeRole::addRoom(Room* room) {
    this->mRoomsAdministered.push_back(room);
}

void AdministrativeRole::removeRoom(std::string name) {
    std::vector<Room*>::iterator it;
    bool valide = false;
    for (it = mRoomsAdministered.begin(); it != mRoomsAdministered.end(); it++) {
        if ((*it)->get_Name() == name) {
            mRoomsAdministered.erase(it);
            valide = true;
            break;
        }
    }
    if(!valide)
        throw std::runtime_error("Room could not be found!");
}


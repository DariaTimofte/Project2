//
//  AdministrativeRole.h
//  Project2
//
//  Created by Daria Timofte on 06/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef AdministrativeRole_h
#define AdministrativeRole_h

#include <iostream>
#include "Role.h"
#include "Room.h"
#include <vector>

class AdministrativeRole : public Role {
public:
    AdministrativeRole();
    AdministrativeRole(std::vector<Room*> rooms);
    AdministrativeRole(Room* room);
    Room* getRoom(std::string name);
    std::vector<Room*> getAllRooms();
    void addRoom(Room* room);
    void removeRoom(std::string name);
private:
    std::vector<Room*> mRoomsAdministered;
};


#endif /* AdministrativeRole_h */

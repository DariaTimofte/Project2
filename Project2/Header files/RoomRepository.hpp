#ifndef RoomRepository_h
#define RoomRepository_h

#include "Repository.hpp"
#include "Room.hpp"

class RoomRepository: public Repository<Room> {
public:
    Room* findByName(std::string name);
    long size();
};

#endif /*  RoomRepository_h */


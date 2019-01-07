
#include "Room.hpp"



Room::Room(std::string room)
{
	this->mName = room;
}

std::string Room::get_Name() {
    return this->mName;
}


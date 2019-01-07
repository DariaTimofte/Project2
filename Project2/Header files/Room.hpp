//
//  Room.h
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef Room_h
#define Room_h

#include <iostream>
class Room
{
public:
    Room();
    Room(std::string);
    void set_Name(std::string);
    std::string get_Name();
protected:
    std::string mName;
};

#endif /* Room_h */

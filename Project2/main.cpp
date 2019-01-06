//
//  main.cpp
//  Project2
//
//  Created by Daria Timofte on 06/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#include<iostream>
#include "Teacher.h"
#include"Student.h"
#include "Room.h"
#include "Activity.h"
#include "ConsoleApplication2.h"

int main()
{
    Person p;
    std::cin >> p;
    std::cout << p;
    Student s;
    std::cin >> s;
    std::cout << s;
    
    std::vector<Person*> persons;
    std::vector<Room*> rooms;
    std::vector<Activity*> activities;
    
    rooms.push_back(new Room("A3"));
    persons.push_back(new Person("Andrei"));
    activities.push_back(new Activity("POO"));
    
    
    return 0;
}

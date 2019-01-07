//
//  Menu.hpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "PersonRepository.hpp"
#include "RoomRepository.hpp"

class Menu {
public:
    enum Type {
        PERSON = 1,
        EXIT
    };
    
    //check inout
    bool checkInput(std::string);
    
    //menu
    void startMenu();
    void personMenu();
    void activityMenu();
    void disciplineMenu();
    void classBookMenu();
    void repositoryMenu();
    
    //person menu
    void addPerson();
    void addRole(Person*);
    void deletePerson();
    void removeRole();
    void editPerson();
    
private:
    PersonRepository persons;
    RoomRepository rooms;
};


#endif /* Menu_hpp */

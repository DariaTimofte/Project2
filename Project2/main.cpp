//
//  main.cpp
//  Project2
//
//  Created by Daria Timofte on 06/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#include <iostream>
#include "Teacher.hpp"
#include "Student.hpp"
#include "Activity.hpp"
#include "Room.hpp"
#include "Role.hpp"
#include "Person.hpp"
#include "StudentRole.hpp"
#include "TeacherRole.hpp"
#include "PersonRepository.hpp"
#include "RoomRepository.hpp"
#include "ActivityRepository.hpp"
#include "ClassBook.hpp"
#include <vector>
#include "Menu.hpp"


int main() {
    
    //teacher class
     Teacher t;
     std::cin >> t;
     std::cout << t;
    //student class
     Student s;
     std::cin >> s;
     std::cout << s;
    
    //person class, room class, activity class
     int n;
     std::vector<Person*> p;
     std::cout << "Introduceti numarul de persoane: ";
     std::cin >> n;
     for (int i = 0; i < n; i++) {
     Teacher *t = new Teacher;
     std::cin >> *t;
     p.push_back(t);
     }
     for (int i = 0; i < n; i++) {
     std::cout << *p[i];
     }
     
     std::cout << "Introduceti numarul de persoane: ";
     int m;
     std::cin >> m;
     for (int i = 0; i < m; i++) {
     Student *s = new Student;
     std::cin >> *s;
     p.push_back(s);
     }
     for (int i = 0; i < n + m; i++) {
         int role = i;
     std::cout << p[i]->getRole(role);
     }
     
     std::vector<Person*> pers;
     std::vector<Room*> rooms;
     std::vector<Activity*> activ;
     
     rooms.push_back(new Room("Sala 321"));
     pers.push_back(new Person("Daria", "Timofte", 2804));
     activ.push_back(new Activity(rooms[0], pers[0], "Laborator POO"));
     pers[0]->addRole(new TeacherRole);
     int role=1;
     std::cout << pers[0]->getRole(role);
    
    //PersonRepository
     PersonRepository pr;
     pr.add(new Person("Daria", "Timofte", 2804, "daria@Yyahoo.com"));
     pr.add(new Person("Ana", "Timofte", 4028, "ana@yahoo.com"));
     Person* p1 = NULL;
     try {
     p1 = pr.searchByEmail("daria@yahoo.com");
     } catch (std::runtime_error const e) {
     std::cout << e.what() << "\n";
     }
     p1->addRole(new StudentRole(24, 2, 252, "buget"));
     p1->addRole(new TeacherRole);
     if (p1 != NULL) {
     std::cout << p1->getEmail() << "\n";
     }
     
     std::vector<Person*> person;
     try {
     person = pr.searchByRole(2);
     } catch (std::runtime_error const e) {
     std::cout << e.what() << "\n";
     }
     for (int i = 0; i < person.size(); i++) {
     std::cout << person[i]->getFirstName() << "\n";
     }
    
    //ClassBook
     ClassBook cl(252, "2018-2019");
     try {
     cl.addStudent(p1);
     } catch (std::runtime_error const e) {
     std::cout << e.what() << "\n";
     }
     Person* s2;
     s2 = pr.searchByEmail("ana@yahoo.com");
     s2->addRole(new StudentRole(100, 2, 252, "buget"));
     s2->addRole(new TeacherRole);
     std::cout << cl.getSize() << "\n";
     cl.addStudent(s2);
     std::cout << cl.getSize() << "\n";
     cl.removeByCNP(4028);
     std::cout << cl.getSize() << "\n";
    
    //Discipline class
     Discipline d("POO", new Activity);
     Person *p2 = new Person("Daria", "Timofte", 2804, "daria@yahoo.com");
     p2->addRole(new StudentRole(28, 2, 252, "buget"));
     try {
     p2->addRole(new StudentRole(68,2,254,"taxa"));
     } catch (std::runtime_error const e) {
     std::cout << e.what() << "\n";
     }
     StudentRole* s3 = dynamic_cast<StudentRole*>(p2->displayRole(1));
     std::cout << s3->getMarksSize() << "\n";
     d.addParticipant(p2);
     std::cout << s3->getMarksSize() << "\n";
    
    //RoomRepository
    RoomRepository rr;
    Room* r;
    rr.add(new Room("Sala 200"));
    rr.add(new Room("Amf. Haret"));
    r = rr.findByName("Amf. Haret");
    std::cout << rr.findByName("Amf. Haret")->get_Name() << "\n";
    std::cout << rr.size() << "\n";
    rr.remove(r);
    std::cout << rr.size() << "\n";
    
    
    
    Menu startMenu;
    startMenu.startMenu();
    return 0;
    
}

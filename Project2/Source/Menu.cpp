//
//  Menu.cpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#include "Menu.hpp"
#include "StudentRole.hpp"
#include "TeacherRole.hpp"
#include "AdministrativeRole.hpp"
#include "GuestRole.hpp"
#include <string>


bool Menu::checkInput(std::string input) {
    int number = 0;
    try {
        number = std::stoi(input);
    } catch(std::invalid_argument) {
        return false;
    }
    return true;
}

//menu
void Menu::startMenu() {
initialStart:
    
    std::cout << "Start Menu\n\n";
    std::cout << " Persons";
    std::string inputString;
    
start:
    
    do {
        std::cout << ">";
        std::cin >> inputString;
    } while (!checkInput(inputString));
    int input = std::stoi(inputString);
    switch (input) {
        case Type::PERSON:
            system("clear");
            personMenu();
            system("clear");
            goto initialStart;
            
        
        case Type::EXIT:
            system("clear");
            break;
            
        default:
            std::cout << "Wrong input!\n";
            goto start;
    }
}
//person menu
void Menu::personMenu() {
    enum Type {
        ADD_PERSON = 1,
        DELETE_PERSON,
        MODIFY_PERSON,
        ADD_ROLE,
        REMOVE_ROLE,
        RETURN
    };
initialStart:
    
    std::cout << "Person Menu\n\n";
    std::cout << "1. Add Persons\n2. Delete Persons\n3. Modify Persons\n4. Add role to a person\n5. Remove role from a person\n\n6. Return\n\n";
    std::string inputString;
    
start:
    
    do {
        std::cout << ">";
        std::cin >> inputString;
    } while (!checkInput(inputString));
    int input = std::stoi(inputString);
    switch (input) {
        case ADD_PERSON:
            system("clear");
            addPerson();
            system("clear");
            goto initialStart;
            
        case DELETE_PERSON:
            system("clear");
            deletePerson();
            system("clear");
            goto initialStart;
            
        case MODIFY_PERSON:
            system("clear");
            editPerson();
            system("clear");
            goto initialStart;
            
        case ADD_ROLE: {
            system("clear");
            std::string firstName, lastName;
            std::cout << "Enter first name= ";
            std::cin >> firstName;
            std::cout << "Enter last name= ";
            std::cin >> lastName;
            Person* person;
            try {
                person = persons.searchByFullName(firstName, lastName);
            } catch (std::runtime_error const e) {
                std::cout << e.what() << "\n";
                goto initialStart;
            }
            
            addRole(person);
            system("clear");
            goto initialStart;
        }
            
        case REMOVE_ROLE:
            system("clear");
            removeRole();
            system("clear");
            goto initialStart;
            
        case RETURN:
            system("clear");
            break;
            
        default:
            std::cout << "Wrong input!\n";
            goto start;
    }
}

void Menu::addPerson() {
    Person* person = new Person();
    std::cin >> *person;
    std::cout << "Do you want this person to have a role?\n1. Yes\n2. No\n\n";
    std::string inputString;
    
start:
    
    do {
        std::cout << ">";
        std::cin >> inputString;
    } while (!checkInput(inputString));
    int input = std::stoi(inputString);
    switch (input) {
        case 1:
            addRole(person);
            system("clear");
            break;
            
        case 2:
            system("clear");
            break;
            
        default:
            std::cout << "Wrong input!\n";
            goto start;
    }
    persons.add(person);
}

void Menu::addRole(Person* person) {
    enum Type {
        STUDENT_ROLE = 1,
        TEACHER_ROLE,
        ADMINISTRATIVE_ROLE,
        GUEST_ROLE,
        RETURN
    };
    
startInitial:
    
    std::cout << "1. Student role\n2. Teacher role\n3. Administrative role\n4. Guest role\n\n5. Return\n\n";
    
start:
    
    std::string inputString;
    do {
        std::cout << ">";
        std::cin >> inputString;
    } while (!checkInput(inputString));
    int input = std::stoi(inputString);
    switch (input) {
        case STUDENT_ROLE: {
            int iDNumber;
            std:: cout << "Enter iD number= ";
            std::cin >> iDNumber;
            int studyYear;
            std:: cout << "Enter study year= ";
            std::cin >> studyYear;
            std::string financialForm;
            std:: cout << "Enter financial form= ";
            std::cin >> financialForm;
            int studyGroup;
            std:: cout << "Enter study group= ";
            std::cin >> studyGroup;
            try {
                person->addRole(new StudentRole(iDNumber, studyYear, studyGroup, financialForm));
            } catch (std::runtime_error const e) {
                std::cout << e.what() << "\n";
                goto startInitial;
            }
            system("clear");
            goto startInitial;
        }
            
        case TEACHER_ROLE: {
            std::string studies;
            std::cout << "Enter studies= ";
            std::cin >> studies;
            std::string didacticFunction;
            std::cout << "Enter didactic function= ";
            std::cin >> didacticFunction;
            try {
                person->addRole(new TeacherRole(studies, didacticFunction));
            } catch (std::runtime_error const e) {
                std::cout << e.what() << "\n";
                goto startInitial;
            }
            system("clear");
            goto startInitial;
        }
            
        case ADMINISTRATIVE_ROLE: {
            try {
                person->addRole(new AdministrativeRole());
            } catch (std::runtime_error const e) {
                std::cout << e.what() << "\n";
                goto startInitial;
            }
            system("clear");
            goto startInitial;
        }
            
        case GUEST_ROLE: {
            try {
                person->addRole(new GuestRole());
            } catch (std::runtime_error const e) {
                std::cout << e.what() << "\n";
                goto startInitial;
            }
            system("clear");
            goto startInitial;
        }
            
        case RETURN:
            system("clear");
            break;
            
        default:
            std::cout << "Wrong input!\n";
            goto start;
    }
}

void Menu::deletePerson() {
    enum Type {
        DELETE_BY_FULLNAME = 1,
        DELETE_BY_CNP,
        RETURN
    };
startInitial:
    
    std::cout << "1. Delete by full name\n2. Delete by CNP\n\n3. Return\n\n";
    
start:
    
    std::string inputString;
    do {
        std::cout << ">";
        std::cin >> inputString;
    } while (!checkInput(inputString));
    int input = std::stoi(inputString);
    switch (input) {
        case DELETE_BY_FULLNAME: {
            std::string firstName, lastName;
            std::cout << "Enter first name= ";
            std::cin >> firstName;
            std::cout << "Enter last name= ";
            std::cin >> lastName;
            Person* person;
            try {
                person = persons.searchByFullName(firstName, lastName);
            } catch (std::runtime_error const e) {
                std::cout << e.what() << "\n";
                goto startInitial;
            }
            persons.remove(person);
            system("clear");
            goto startInitial;
        }
        case DELETE_BY_CNP: {
            int CNP;
            std::cout << "Enter CNP= ";
            std::cin >> CNP;
            Person* person;
            try {
                person = persons.searchByCNP(CNP);
            } catch (std::runtime_error const e) {
                std::cout << e.what() << "\n";
                goto startInitial;
            }
            persons.remove(person);
            system("clear");
            goto startInitial;
        }
            
        case RETURN:
            system("clear");
            break;
            
        default:
            std::cout << "Wrong input!\n";
            goto start;
    }
}

void Menu::removeRole() {
    std::string firstName, lastName;
    
start_initial:
    
    std::cout << "Enter first name= ";
    std::cin >> firstName;
    std::cout << "Enter last name= ";
    std::cin >> lastName;
    Person* person;
    try {
        person = persons.searchByFullName(firstName, lastName);
    } catch (std::runtime_error const e) {
        std::cout << e.what() << "\n";
        goto start_initial;
    }
    
start:
    
    std::cout << "Enter role you want to remove= ";
    std::string roleString;
    std::cin >> roleString;
    int role = 0;
    if (roleString == "student") {
        role = 1;
    } else if (roleString == "teacher") {
        role = 2;
    } else if (roleString == "guest") {
        role = 3;
    } else if (roleString == "administrative") {
        role = 4;
    } else {
        std::cout << "Role invalid! Pick one from the list below:\nstudent\nteacher\nguest\nadministrative\n";
        goto start;
    }
    person->removeRole(role);
}

void Menu::editPerson() {
    enum type {
        FIRST_NAME = 1,
        LAST_NAME,
        CNP,
        EMAIL,
        RETURN
    };
    
initialStart:
    
    std::string firstName, lastName, email;
    int cnp;
    Person* person;
    std::cout << "What person do you want to edit?\nEnter first name= ";
    std::cin >> firstName;
    std::cout << "Enter last name= ";
    std::cin >> lastName;
    try {
        person = persons.searchByFullName(firstName, lastName);
    } catch (std::runtime_error const e) {
        std::cout << e.what() << "\n";
        goto initialStart;
    }
    
start_1:
    
    std::cout << "What do you want to edit?\n1. First name\n2. Last name\n3. CNP\n4. Email\n\n5. Return\n\n";
    std::string inputString;
    
start_2:
    
    do {
        std::cout << ">";
        std::cin >> inputString;
    } while (!checkInput(inputString));
    int input = std::stoi(inputString);
    switch (input) {
        case FIRST_NAME: {
            std::cout << "Enter the new first name= ";
            std::cin >> firstName;
            person->setFirstName(firstName);
            goto start_1;
        }
            
        case LAST_NAME: {
            std::cout << "Enter the new last name= ";
            std::cin >> lastName;
            person->setLastName(lastName);
            goto start_1;
        }
            
        case CNP: {
            std::cout << "Enter the new CNP= ";
            std::cin >> cnp;
            person->setCNP(cnp);
            goto start_1;
        }
            
        case EMAIL: {
            std::cout << "Enter the new email= ";
            std::cin >> email;
            person->setEmail(email);
            goto start_1;
        }
            
        case RETURN:
            system("clear");
            break;
            
        default:
            std::cout << "Wrong input!\n";
            goto start_2;
    }
}

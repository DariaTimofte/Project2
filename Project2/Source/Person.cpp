//
//  Person.cpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#include "Person.hpp"
#include "TeacherRole.hpp"
#include "StudentRole.hpp"
#include "GuestRole.hpp"
#include "AdministrativeRole.hpp"
#include <string>

Person::Person(std::string FirstName, std::string LastName, int CNP, std::string Email) {
    this->mCNP = CNP;
    this->mFirstName = FirstName;
    this->mLastName = LastName;
    this->mEmail = Email;
}

Person::Person(std::string FirstName, std::string LastName, int CNP, std::string Role, std::string Email) {
    this->mCNP = CNP;
    this->mFirstName = FirstName;
    this->mLastName = LastName;
    this->mEmail = Email;
    if (Role == "student") {
        this->mRoles.push_back(new StudentRole);
    } else if (Role == "teacher"){
        this->mRoles.push_back(new TeacherRole);
    } else if (Role == "guest") {
        this->mRoles.push_back(new GuestRole);
    } else if (Role == "administrative") {
        this->mRoles.push_back(new AdministrativeRole);
    } else {
        throw std::runtime_error("Role does not exist!");
    }
}

std::istream& operator >> (std::istream& stream, Person& object) {
    std::cout << "Enter CNP= ";
    stream >> object.mCNP;
    std::cout << "Enter email= ";
    stream >> object.mEmail;
    std::cout << "Enter first name= ";
    stream >> object.mFirstName;
    std::cout << "Enter last name= ";
    stream >> object.mLastName;
    return stream;
}

std::ostream& operator << (std::ostream& stream, Person& object) {
    stream << "CNP= " << object.mCNP << "\n";
    stream << "Email= " << object.mEmail << "\n";
    stream << "First name= " << object.mFirstName << "\n";
    stream << "Last name= " <<object.mLastName << "\n";
    StudentRole* studentRole;
    TeacherRole* teacherRole;
    if (object.isStudent()) {
        studentRole = dynamic_cast<StudentRole*>(object.displayRole(1));
        stream << "ID number= ";
        stream << studentRole->getIDNumber() << "\n";
        stream << "Study year= ";
        stream << studentRole->getStudyYear() << "\n";
        stream << "Study group= ";
        stream << studentRole->getStudyGroup() << "\n";
        stream << "Financial form= ";
        stream << studentRole->getFinancialForm() << "\n";
        for (int i = 0; i < studentRole->getMarksSize(); i++) {
            stream << "Student has " << studentRole->getMark(i)->getMark() << " at discipline " << studentRole->getMark(i)->getDiscipline() << ".\n";
        }
        
    }
    if (object.isTeacher()) {
        teacherRole = dynamic_cast<TeacherRole*>(object.displayRole(2));
        stream << "Studies= ";
        stream << teacherRole->getStudies() << "\n";
        stream << "Didactic function= ";
        stream << teacherRole->getDidacticFunction() << "\n";
    }
    return stream;
}

void Person::setFirstName(std::string FirstName) {
    this->mFirstName =FirstName;
}

void Person::setLastName(std::string LastName) {
    this->mLastName = LastName;
}

void Person::setEmail(std::string Email) {
    this->mEmail = Email;
}

void Person::setCNP(int CNP) {
    this->mCNP = CNP;
}

std::string Person::getFirstName() {
    return this->mFirstName;
}

std::string Person::getLastName() {
    return this->mLastName;
}

std::string Person::getEmail() {
    return this->mEmail;
}

int Person::getCNP() {
    return this->mCNP;
}

Person::Person() {
    
}

void Person::addRole(Role* role) {
    std::vector<Role*>::iterator it;
    for (it = mRoles.begin(); it != mRoles.end(); it++) {
        if ((*it)->getRole() == role->getRole()) {
            throw std::runtime_error("Role already exists!");
        }
    }
    mRoles.push_back(role);
}

Role* Person::displayRole(int role) {
    for (int i = 0; i < mRoles.size(); i++) {
        if (role == mRoles[i]->getRole())
            return mRoles[i];
    }
    throw std::runtime_error("Role could not be found");
}

Role::RoleType Person::getRole(int role) {
    for (int i = 0; i < mRoles.size(); i++) {
        if (role == mRoles[i]->getRole())
            return mRoles[i]->getRole();
    }
    throw std::runtime_error("Role could not be found");
}

void Person::removeRole(int role) {
    std::vector<Role*>::iterator it;
    for (it = mRoles.begin(); it != mRoles.end(); it++) {
        if ((*it)->getRole() == role) {
            mRoles.erase(it);
            break;
        }
    }
}

bool Person::isStudent() {
    std::vector<Role*>::iterator it;
    for (it = mRoles.begin(); it != mRoles.end(); it++) {
        if ((*it)->getRole() == 1) {
            return true;
        }
    }
    return false;
}

bool Person::isTeacher() {
    std::vector<Role*>::iterator it;
    for (it = mRoles.begin(); it != mRoles.end(); it++) {
        if ((*it)->getRole() == 2) {
            return true;
        }
    }
    return false;
}



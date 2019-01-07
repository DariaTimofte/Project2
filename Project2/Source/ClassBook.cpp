//
//  ClassBook.cpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#include "Classbook.hpp"
#include "StudentRole.hpp"

Classbook::Classbook()
{
}


Classbook::~Classbook()
{
}

Classbook::Classbook(int studyGroup, std::string year) {
    this->mStudyGroup = studyGroup;
    this->mYear = year;
}

void Classbook::set_Year(std::string Year)
{
    mYear = Year;
}

std::string Classbook::get_Year()
{
    return mYear;
}

void Classbook::set_StudyGroup(int StudyGroup)
{
    mStudyGroup = StudyGroup;
}

int Classbook::get_StudyGroup()
{
    return mStudyGroup;
}

std::vector<Person*>::iterator it;

void Classbook::addStudent(Person * person) {
    StudentRole* p = dynamic_cast<StudentRole*>(person->displayRole(1));
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        if ((*it)->get_CNP() == person->get_CNP()) {
            throw std::runtime_error("Person already exists!");
        }
    }
    if (p->get_StudyGroup() != mStudyGroup) {
        throw std::runtime_error("Person not from this group!");
    }
    try {
        person->getRole(1);
    }
    catch (std::runtime_error const e) {
        throw std::runtime_error("Not a student");
    }
    mClassbook.push_back(person);
}

void Classbook::removeByCNP(std::string CNP) {
    bool valide = false;
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        if ((*it)->get_CNP() == CNP) {
            mClassbook.erase(it);
            valide = true;
            break;
        }
    }
    if (!valide) {
        throw std::runtime_error("Person could not be found!");
    }
}

void Classbook::removeByEmail(std::string email) {
    bool valide = false;
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        if ((*it)->get_Email() == email) {
            mClassbook.erase(it);
            valide = true;
            break;
        }
    }
    if (!valide) {
        throw std::runtime_error("Person could not be found!");
    }
}

void Classbook::removeByFullName(std::string firstName, std::string lastName) {
    bool valide = false;
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        if ((*it)->get_FirstName() == firstName && (*it)->get_LastName() == lastName) {
            mClassbook.erase(it);
            valide = true;
            break;
        }
    }
    if (!valide) {
        throw std::runtime_error("Person could not be found!");
    }
}

Person* Classbook::searchByLastName(std::string lastName) {
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        if ((*it)->get_LastName() == lastName)
            return *it;
    }
    throw std::runtime_error("Person could not be found!");
}

Person* Classbook::searchByFirstName(std::string firstName) {
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        if ((*it)->get_FirstName() == firstName)
            return *it;
        
    }
    throw std::runtime_error("Person could not be found!");
}

Person* Classbook::searchByFullName(std::string firstName, std::string lastName) {
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        if ((*it)->get_LastName() == lastName && (*it)->get_FirstName() == firstName)
            return *it;
    }
    throw std::runtime_error("Person could not be found!");
}

Person* Classbook::searchByCNP(std::string CNP) {
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        if ((*it)->get_CNP() == CNP)
            return *it;
    }
    throw std::runtime_error("Person could not be found!");
}

Person* Classbook::searchByEmail(std::string email) {
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        if ((*it)->get_Email() == email)
            return *it;
    }
    throw std::runtime_error("Person could not be found!");
}

std::vector<Person*> Classbook::getClassBook() {
    std::vector<Person*> students;
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        students.push_back(*it);
    }
    return students;
}

void Classbook::addMark(float mark, Discipline* discipline, std::string firstName, std::string lastName) {
    StudentRole *student = NULL;
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        if ((*it)->get_LastName() == lastName && (*it)->get_FirstName() == firstName) {
            student = dynamic_cast<StudentRole*>((*it)->displayRole(1));
            break;
        }
    }
    student->addMark(mark, discipline);
}

void Classbook::removeMark(std::string discipline, std::string firstName, std::string lastName) {
    StudentRole *student = NULL;
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        if ((*it)->get_LastName() == lastName && (*it)->get_FirstName() == firstName) {
            student = dynamic_cast<StudentRole*>((*it)->displayRole(1));
            break;
        }
    }
    student->removeMark(discipline);
}

void Classbook::updateMark(float mark, std::string discipline, std::string firstName, std::string lastName) {
    StudentRole *student = NULL;
    for (it = mClassbook.begin(); it != mClassbook.end(); it++) {
        if ((*it)->get_LastName() == lastName && (*it)->get_FirstName() == firstName) {
            student = dynamic_cast<StudentRole*>((*it)->displayRole(1));
            break;
        }
    }
    student->updateMark(mark, discipline);
}

long Classbook::getSize() {
    return mClassbook.size();
}

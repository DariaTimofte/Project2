//
//  ClassBook.cpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#include "ClassBook.hpp"
#include "StudentRole.hpp"

ClassBook::ClassBook(int studyGroup, std::string year) {
    this->mStudyGroup = studyGroup;
    this->mYear = year;
}

std::vector<Person*>::iterator it;

void ClassBook::addStudent(Person * person) {
    StudentRole* p = dynamic_cast<StudentRole*>(person->displayRole(1));
    for (it = mClassBook.begin(); it != mClassBook.end(); it++) {
        if ((*it)->getCNP() == person->getCNP()) {
            throw std::runtime_error("Person already exists!");
        }
    }
    if (p->getStudyGroup() != mStudyGroup) {
        throw std::runtime_error("Person not from this group!");
    }
    try {
        person->getRole(1);
    } catch (std::runtime_error const e) {
        throw std::runtime_error("Not a student");
    }
    mClassBook.push_back(person);
}

void ClassBook::removeByCNP(int CNP) {
    bool valide = false;
    for (it = mClassBook.begin(); it != mClassBook.end(); it++) {
        if ((*it)->getCNP() == CNP) {
            mClassBook.erase(it);
            valide = true;
            break;
        }
    }
    if (!valide) {
        throw std::runtime_error("Person could not be found!");
    }
}

void ClassBook::removeByEmail(std::string email) {
    bool valide = false;
    for (it = mClassBook.begin(); it != mClassBook.end(); it++) {
        if ((*it)->getEmail() == email) {
            mClassBook.erase(it);
            valide = true;
            break;
        }
    }
    if (!valide) {
        throw std::runtime_error("Person could not be found!");
    }
}

void ClassBook::removeByFullName(std::string firstName, std::string lastName) {
    bool valide = false;
    for (it = mClassBook.begin(); it != mClassBook.end(); it++) {
        if ((*it)->getFirstName() == firstName && (*it)->getLastName() == lastName) {
            mClassBook.erase(it);
            valide = true;
            break;
        }
    }
    if (!valide) {
        throw std::runtime_error("Person could not be found!");
    }
}

Person* ClassBook::searchByLastName(std::string lastName) {
    for (it = mClassBook.begin(); it != mClassBook.end() ; it++) {
        if ((*it)->getLastName() == lastName)
            return *it;
    }
    throw std::runtime_error("Person could not be found!");
}

Person* ClassBook::searchByFirstName(std::string firstName) {
    for (it = mClassBook.begin(); it != mClassBook.end(); it++) {
        if ((*it)->getFirstName() == firstName)
            return *it;
        
    }
    throw std::runtime_error("Person could not be found!");
}

Person* ClassBook::searchByFullName(std::string firstName, std::string lastName) {
    for (it = mClassBook.begin(); it != mClassBook.end(); it++) {
        if ((*it)->getLastName() == lastName && (*it)->getFirstName() == firstName)
            return *it;
    }
    throw std::runtime_error("Person could not be found!");
}

Person* ClassBook::searchByCNP(int CNP) {
    for (it = mClassBook.begin(); it != mClassBook.end(); it++) {
        if((*it)->getCNP() == CNP)
            return *it;
    }
    throw std::runtime_error("Person could not be found!");
}

Person* ClassBook::searchByEmail(std::string email) {
    for (it = mClassBook.begin(); it != mClassBook.end(); it++) {
        if((*it)->getEmail() == email)
            return *it;
    }
    throw std::runtime_error("Person could not be found!");
}

std::vector<Person*> ClassBook::getClassBook() {
    std::vector<Person*> students;
    for (it = mClassBook.begin(); it != mClassBook.end(); it++) {
        students.push_back(*it);
    }
    return students;
}

void ClassBook::addMark(float mark, Discipline* discipline, std::string firstName, std::string lastName) {
    StudentRole *student = NULL;
    for(it = mClassBook.begin(); it != mClassBook.end(); it++) {
        if ((*it)->getLastName() == lastName && (*it)->getFirstName() == firstName) {
            student = dynamic_cast<StudentRole*>((*it)->displayRole(1));
            break;
        }
    }
    student->addMark(mark, discipline);
}

void ClassBook::removeMark(std::string discipline, std::string firstName, std::string lastName) {
    StudentRole *student = NULL;
    for(it = mClassBook.begin(); it != mClassBook.end(); it++) {
        if ((*it)->getLastName() == lastName && (*it)->getFirstName() == firstName) {
            student = dynamic_cast<StudentRole*>((*it)->displayRole(1));
            break;
        }
    }
    student->removeMark(discipline);
}

void ClassBook::updateMark(float mark, std::string discipline, std::string firstName, std::string lastName) {
    StudentRole *student = NULL;
    for(it = mClassBook.begin(); it != mClassBook.end(); it++) {
        if ((*it)->getLastName() == lastName && (*it)->getFirstName() == firstName) {
            student = dynamic_cast<StudentRole*>((*it)->displayRole(1));
            break;
        }
    }
    student->updateMark(mark, discipline);
}

long ClassBook::getSize() {
    return mClassBook.size();
}

int ClassBook::getStudyGroup() {
    return this->mStudyGroup;
}

std::string ClassBook::getYear() {
    return this->mYear;
}

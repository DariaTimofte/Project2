//
//  StudentRole.cpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#include "StudentRole.hpp"

StudentRole::StudentRole()
:Role(Role::STUDENT_ROLE)
{}

StudentRole::StudentRole(int IDNumber, int studyYear, int studyGroup, std::string financialForm)
:Role(Role::STUDENT_ROLE) {
    this->mIDNumber = IDNumber;
    this->mStudyYear = studyYear;
    this->mStudyGroup = studyGroup;
    this->mFinancialForm = financialForm;
}

int StudentRole::getIDNumber() {
    return this->mIDNumber;
}

int StudentRole::getStudyYear() {
    return this->mStudyYear;
}

std::string StudentRole::getFinancialForm() {
    return this->mFinancialForm;
}

int StudentRole::getStudyGroup() {
    return this->mStudyGroup;
}

long StudentRole::getMarksSize() {
    return this->mMarks.size();
}

float StudentRole::getMarkByDiscipline(std::string name) {
    std::vector<Mark*>::iterator it;
    for (it = mMarks.begin(); it != mMarks.end(); it++) {
        if ((*it)->getDiscipline() == name)
            return (*it)->getMark();
    }
    throw std::runtime_error("Discipline could not be found");
}

void StudentRole::setIDNumber(int IDNumber) {
    this->mIDNumber = IDNumber;
}

void StudentRole::setStudieYear(int studyYear) {
    this->mStudyYear = studyYear;
}

void StudentRole::setFinancialForm(std::string financialForm) {
    this->mFinancialForm = financialForm;
}

void StudentRole::addMark(Mark* mark) {
    mMarks.push_back(mark);
}

void StudentRole::addMark(float mark, Discipline* discipline) {
    if(isMarkSet(discipline)) {
        updateMark(mark, discipline->getName());
    } else {
        this->mMarks.push_back(new Mark(mark, discipline));
    }
}

void StudentRole::removeMark(std::string discipline) {
    std::vector<Mark*>::iterator it;
    for (it = mMarks.begin(); it != mMarks.end(); it++) {
        if ((*it)->getDiscipline() == discipline) {
            mMarks.erase(it);
            break;
        }
    }
}

void StudentRole::updateMark(float mark, std::string discipline) {
    std::vector<Mark*>::iterator it;
    for (it = mMarks.begin(); it != mMarks.end(); it++) {
        if ((*it)->getDiscipline() == discipline) {
            (*it)->setMark(mark);
            break;
        }
    }
}

void StudentRole::setStudyGroup(int studyGroup) {
    this->mStudyGroup = studyGroup;
}

Mark *StudentRole::getMark(int iterator) {
    return this->mMarks[iterator];
}

bool StudentRole::isMarkSet(Discipline *discipline) {
    std::vector<Mark*>::iterator it;
    for (it = mMarks.begin(); it != mMarks.end(); it++) {
        if ((*it)->getDiscipline() == discipline->getName()) {
            return true;
        }
    }
    return false;
}



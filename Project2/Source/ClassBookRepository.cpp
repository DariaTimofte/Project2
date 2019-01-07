//
//  ClassBookRepository.cpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#include "ClassBookRepository.hpp"

ClassBook* ClassBookRepository::searchByStudyGroupAndYear(int studyGroup, std::string year) {
    for(int i = 0; i < mEntities.size(); i++) {
        if(mEntities[i]->getStudyGroup() == studyGroup && mEntities[i]->getYear() == year)
            return mEntities[i];
    }
    throw std::runtime_error("Class book of this study group could not be found!");
}

Person* ClassBookRepository::searchByFullNameAndYear(std::string firstName, std::string lastName, std::string year) {
    Person* person = NULL;
    for (int i = 0; i < mEntities.size(); i++) {
        try {
            person = mEntities[i]->searchByFullName(firstName, lastName);
        } catch (std::runtime_error const e) {}
        if (person != NULL && mEntities[i]->getYear() == year)
            return person;
    }
    throw std::runtime_error("Person could not be found!");
}

Person* ClassBookRepository::searchByCNPAndYear(int CNP, std::string year) {
    Person* person = NULL;
    for (int i = 0; i < mEntities.size(); i++) {
        try {
            person = mEntities[i]->searchByCNP(CNP);
        } catch (std::runtime_error const e) {}
        if (person != NULL && mEntities[i]->getYear() == year)
            return person;
    }
    throw std::runtime_error("Person could not be found!");
}

Person* ClassBookRepository::searchByEmailAndYear(std::string email, std::string year) {
    Person* person = NULL;
    for (int i = 0; i < mEntities.size(); i++) {
        try {
            person = mEntities[i]->searchByEmail(email);
        } catch (std::runtime_error const e) {}
        if (person != NULL && mEntities[i]->getYear() == year)
            return person;
    }
    throw std::runtime_error("Person could not be found!");
}

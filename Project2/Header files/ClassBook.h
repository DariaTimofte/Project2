//
//  ClassBook.h
//  Project2
//
//  Created by Daria Timofte on 06/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef ClassBook_h
#define ClassBook_h

#include "Person.h"
#include "

class ClassBook {
public:
    ClassBook(int studyGroup, std::string year);
    void addStudent(Person* person);
    void removeByCNP(int CNP);
    void removeByEmail(std::string email);
    void removeByFullName(std::string firstName, std::string lastName);
    Person* searchByLastName(std::string lastName);
    Person* searchByFirstName(std::string firstName);
    Person* searchByFullName(std::string firstName, std::string lastName);
    Person* searchByCNP(int CNP);
    Person* searchByEmail(std::string email);
    std::vector<Person*> getClassBook();
    void addMark(float mark, Discipline* discipline, std::string firstName, std::string lastName);
    void removeMark(std::string discipline, std::string firstName, std::string lastName);
    void updateMark(float mark, std::string discipline, std::string firstName, std::string lastName);
    long getSize();
    int getStudyGroup();
    std::string getYear();
private:
    std::string mYear;
    int mStudyGroup;
    std::vector<Person*> mClassBook;
    
};

#endif /* ClassBook_h */

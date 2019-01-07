//
//  ClassBookRepository.hpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef ClassBookRepository_hpp
#define ClassBookRepository_hpp

#include "Repository.hpp"
#include "ClassBook.hpp"

class ClassBookRepository: public Repository<ClassBook> {
public:
    ClassBook* searchByStudyGroupAndYear(int studyGroup, std::string year);
    Person* searchByFullNameAndYear(std::string firstName, std::string lastName, std::string year);
    Person* searchByCNPAndYear(int, std::string);
    Person* searchByEmailAndYear(std::string, std::string);
};
#endif /* ClassBookRepository_hpp */

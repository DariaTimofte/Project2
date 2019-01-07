//
//  DisciplineRepository.hpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef DisciplineRepository_hpp
#define DisciplineRepository_hpp

#include "Repository.hpp"
#include "Discipline.hpp"

class DisciplineRepository: public Repository<Discipline> {
public:
    Discipline* searchByName(std::string);
};

#endif /* DisciplineRepository_hpp */

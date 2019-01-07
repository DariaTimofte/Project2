//
//  DisciplineRepository.cpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#include "DisciplineRepository.hpp"
#include<string>

Discipline* DisciplineRepository::searchByName(std::string name) {
    typename std::vector<Discipline*>::iterator it;
    for (it = mEntities.begin(); it != mEntities.end(); it++) {
        if ((*it)->getName() == name)
            return *it;
    }
    throw std::runtime_error("Discipline could not be found!");
}

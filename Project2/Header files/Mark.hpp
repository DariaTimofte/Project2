//
//  Mark.h
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef Mark_h
#define Mark_h

#include<iostream>
#include "Discipline.hpp"

class Mark {
public:
    Mark(float mark, Discipline* discipline);
    std::string getDiscipline();
    float getMark();
    void setDiscipline(Discipline* discipline);
    void setMark(float mark);
private:
    float mMark;
    Discipline* mDiscipline;
};

#endif /* Mark_h */

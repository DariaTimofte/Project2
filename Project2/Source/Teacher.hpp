//
//  Teacher.hpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef Teacher_hpp
#define Teacher_hpp

#include "Person.hpp"

class Teacher : public Person {
    
public:
    Teacher(std::string,std::string,int);
    Teacher();
    
private:
    std::string Birthdate;
};

#endif /* Teacher_hpp */

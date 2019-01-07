//
//  Course.hpp
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef Course_hpp
#define Course_hpp

#include<iostream>

class Person {
public:
    Person(std::string FirstName, std::string LastName, std::string CNP, std::string Email = "");
protected:
    std::string FirstName;
    std::string LastName;
    std::string CNP;
    std::string Email;
};


#endif /* Course_hpp */

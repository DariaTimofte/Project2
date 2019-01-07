#ifndef Course_h
#define Course_h

#include <iostream>

class Person {
public:
    Person(std::string FirstName, std::string LastName, std::string CNP, std::string Email = "");
protected:
    std::string FirstName;
    std::string LastName;
    std::string CNP;
    std::string Email;
};

#endif /*  Course_h */


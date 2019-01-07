#ifndef Teacher_h
#define Teacher_h

#include <iostream>
#include "Person.hpp"

class Teacher : public Person {
    
public:
    Teacher();
    Teacher(std::string,std::string,int);
    
private:
    std::string Birthdate;
};
#endif /*  Teacher_h */

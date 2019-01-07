#ifndef Student_h
#define Student_h

#include<iostream>
#include "Person.hpp"

class Student : public Person
{
private:
	int nrMatricol;
	int anStudii;
	std::string formaFinantare;
};

#endif /*  Student_h */


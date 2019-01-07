#ifndef PersonRepository_h
#define PersonRepository_h

#include "Repository.hpp"
#include "Person.hpp"

class PersonRepository: public Repository<Person> {
public:
    Person* searchByLastName(std::string lastName);
    Person* searchByFirstName(std::string firstName);
    Person* searchByFullName(std::string firstName, std::string lastName);
    Person* searchByCNP(int CNP);
    Person* searchByEmail(std::string email);
    std::vector<Person*> searchByRole(int role);
    long size();
};

#endif /*  PersonRepository_h */



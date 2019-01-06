#include "Repository.h"
#include "Person.h"

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


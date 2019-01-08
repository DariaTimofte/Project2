#include "PersonRepository.hpp"

Person * PersonRepository::searchByLastName(std::string LastName)
{
    for (int i = 0; i < mEntities.size(); i++)
        if (mEntities[i]->getLastName() == LastName)
            return mEntities[i];
    throw std::runtime_error("Last name couldn't be found!");
    
}

Person * PersonRepository::searchByFirstName(std::string FirstName)
{
    for (int i = 0; i < mEntities.size(); i++)
        if (mEntities[i]->getFirstName() == FirstName)
            return mEntities[i];
    throw std::runtime_error("First name couldn't be found!");
}

Person * PersonRepository::searchByFullName(std::string LastName, std::string FirstName)
{
    for (int i = 0; i < mEntities.size(); i++)
        if (mEntities[i]->getLastName() == LastName && mEntities[i]->getFirstName() == FirstName)
            return mEntities[i];
    throw std::runtime_error("This name couldn't be found!");
}
Person * PersonRepository::searchByCNP(int CNP)
{
    for (int i = 0; i < mEntities.size(); i++)
        if (mEntities[i]->getCNP() == CNP)
            return mEntities[i];
    throw std::runtime_error("This CNP doesn't exist!");
}
Person * PersonRepository::searchByEmail(std::string Email)
{
    for (int i = 0; i < mEntities.size(); i++)
        if (mEntities[i]->getEmail() == Email)
            return mEntities[i];
    throw std::runtime_error("This email couldn't be found!");
}
std::vector<Person*> PersonRepository::searchByRole(int Role)
{
    std::vector<Person*> Persons;
    for (int i = 0; i < mEntities.size(); i++) {
        try {
            if (mEntities[i]->getRole(Role))
                Persons.push_back(mEntities[i]);
        }
        catch (std::runtime_error) {}
    }
    if (Persons.size() != 0)
        return Persons;
    
    throw std::runtime_error("No person has this role!");
    
}

long PersonRepository::size() {
    return mEntities.size();
}

#ifndef Person_h
#define Person_h

#include "Role.hpp"
#include<iostream>
#include<vector>
#include<string>

class Person{
public:
    Person();
    Person(std::string FirstName, std::string LastName, int CNP, std::string Email = "");
    Person(std::string FirstName, std::string LastName, int CNP,std::string Role, std::string Email);
    friend std::istream& operator >> (std::istream&, Person&);
    friend std::ostream& operator << (std::ostream&, Person&);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setCNP(int CNP);
    void setEmail(std::string email);
    std::string getFirstName();
    std::string getLastName();
    std::string getEmail();
    int getCNP();
    void addRole(Role* role);
    void removeRole(int role);
    Role* displayRole(int role);
    Role::RoleType getRole(int role);
    bool isStudent();
    bool isTeacher();
    
protected:
    std::vector <Role*> mRoles;
    std::string mFirstName;
    std::string mLastName;
    int mCNP;
    std::string mEmail;
};

#endif /*  Person_h */


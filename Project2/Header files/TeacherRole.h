#include <iostream>
#include "Role.h"

class TeacherRole:public Role {
public:
    TeacherRole();
    TeacherRole(std::string studies, std::string didacticFunction);
    std::string getStudies();
    std::string getDidacticFunction();
    void setStudies(std::string studies);
    void setDidacticFunction(std::string didacticFunction);
private:
    std::string mStudies;
    std::string mDidacticFunction;
};

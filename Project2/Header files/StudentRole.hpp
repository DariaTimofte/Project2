#ifndef StudentRole_h
#define StudentRole_h

#include <iostream>
#include "Role.hpp"
#include "Mark.hpp"

class StudentRole :
public Role
{
public:
    StudentRole();
    StudentRole(int IDNumber, int studyYear, int studyGroup, std::string financialForm);
    ~StudentRole();
    void setIDNumber(int);
    int getIDNumber();
    void setStudyYear(int);
    int getStudyYear();
    void setStudyGroup(int);
    int getStudyGroup();
    void setFinancialForm(std::string);
    std::string getFinancialForm();
    long getMarksSize();
    float getMarkByDiscipline(std::string name);
    void addMark(Mark* mark);
    void addMark(float mark, Discipline* discipline);
    void removeMark(std::string discipline);
    void updateMark(float mark, std::string discipline);
    Mark* getMark(int iterator);
    bool isMarkSet(Discipline* discipline);

private:
    int mIDNumber;
    int mStudyYear;
    std::string mFinancialForm;
    std::vector<Mark*> mMarks;
    int mStudyGroup;
};

#endif /*  StudentRole_h */


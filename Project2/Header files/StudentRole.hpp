//
//  StudentRole.h
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef StudentRole_h
#define StudentRole_h

#include <iostream>
#include "Role.hpp"
#include "Mark.hpp"

class StudentRole:public Role {
public:
    StudentRole();
    StudentRole(int IDNumber, int studyYear, int studyGroup, std::string financialForm);
    int getIDNumber();
    int getStudyYear();
    std::string getFinancialForm();
    int getStudyGroup();
    long getMarksSize();
    float getMarkByDiscipline(std::string name);
    void setIDNumber(int IDNumber);
    void setStudieYear(int studyYear);
    void setFinancialForm(std::string financialForm);
    void addMark(Mark* mark);
    void addMark(float mark, Discipline* discipline);
    void removeMark(std::string discipline);
    void updateMark(float mark, std::string discipline);
    void setStudyGroup(int studyGroup);
    Mark* getMark(int iterator);
    bool isMarkSet(Discipline* discipline);
private:
    int mIDNumber;
    int mStudyYear;
    std::string mFinancialForm;
    std::vector<Mark*> mMarks;
    int mStudyGroup;
};


#endif /* StudentRole_h */

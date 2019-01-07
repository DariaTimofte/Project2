//
//  Role.h
//  Project2
//
//  Created by Daria Timofte on 07/01/2019.
//  Copyright © 2019 Daria Timofte. All rights reserved.
//

#ifndef Role_h
#define Role_h

#include <iostream>

class Role
{
public:
    Role() {}
    enum RoleType
    {
        STUDENT_ROLE = 1,
        TEACHER_ROLE,
        GUEST_ROLE,
        ADMINISTRATIVE_ROLE
    };
    Role(RoleType);
    virtual ~Role() {}
    RoleType getRole();
    
private:
    RoleType mType;
};

#endif /* Role_h */

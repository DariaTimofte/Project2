#include "Role.hpp"

Role::Role(RoleType type)
{
    this->mType = type;
}
Role::RoleType Role::getRole()
{
    return mType;
}

#ifndef Repository_h
#define Repository_h

#include <iostream>
#include<vector>

template <class Entity>

class Repository {
public:
    void add(Entity* entity) {
        mEntities.push_back(entity);
    }
    void remove(Entity* entity){
        typename std::vector<Entity*>::iterator it;
        for (it = mEntities.begin(); it != mEntities.end(); it++) {
            if (*it == entity) {
                mEntities.erase(it);
                break;
            }
        }
    }
    
protected:
    std::vector<Entity*> mEntities;
};
#endif /*  Repository_h */


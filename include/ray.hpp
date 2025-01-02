#ifndef RAY_H
#define RAY_H

#include "vec3.hpp"


class ray{
    private:
    
    vec3 orig;
    vec3 dir;
    
    public:

    ray(){}
    ray(const vec3& origin, const vec3& direction){
        this->orig = origin;
        this->dir = direction;
    }

    const vec3& origin() const{
        return this->orig;
    }
    
    const vec3& direction() const{
        return this->dir;
    }

    vec3 at(double t) const{
        return this->orig + this->dir * t;    
    }

};

#endif
#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.hpp"

class HitRecord {
    public:
        vec3 point;
        vec3 normal;
        double t; 
};

class Hittable{
    public:
        virtual ~Hittable() = default;
        virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, HitRecord& record) const = 0;
};

#endif 
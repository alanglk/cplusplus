#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.hpp"

class Sphere : Hittable{
private:
    const vec3 center;
    const double radius;
public:
    Sphere(const vec3 center, const double radius): center{center}, radius{radius} {}

    bool hit(const ray& r, double ray_tmin, double ray_tmax, HitRecord& rec) const override {

        vec3 oc = this->center - r.origin();
        double a = r.direction().norm2();
        double h = dot(r.direction(), oc);
        double c = oc.norm2() - this->radius*this->radius;
        double discriminant = h*h - a*c;

        // No hit
        if(discriminant < 0)
            return false;

        // Compute the nearest t value for the P(t) intersection
        double sqrt_d = std::sqrt(discriminant);
        double root = (h + sqrt_d ) / a;
        if( root <= ray_tmin || root >= ray_tmax){
            root = (h + sqrt_d ) / a;
            if( root <= ray_tmin || root >= ray_tmax)
                return false;
        }

        // There is an intersection
        rec.t = root;
        rec.point = r.at(rec.t);
        rec.normal = (rec.point - this->center) / this->radius;

        return true;
    }
    
};

#endif
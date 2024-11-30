#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>
#include <include/image.hpp>

class vec3{
    
    /*
    Operaciones del propio vector
        a.x devuelve x (no modificable)
        a.y devuelve y (no modificable)
        a.z devuelve z (no modificable)
        a.norm() devuelve la norma de a (no modificable)
    Operaciones del vector con otros elementos
        cout << a [std::iostream - vector] imprimir vector
        a * b [escalar - vector] multiplicacion 
        a + b [vector - vector] suma   
        a - b [vector - vector] resta
        a * b [vector - vector] multiplicacion
        a · b [vector - vector] producto escalar
        a x b [vector - vector] producto vectorial
    */

    public:
        double e[3];

        vec3(): e{0, 0, 0}{}
        vec3(double e0, double e1, double e2): e{e0, e1, e2} {}

        // Acceso a posiciones
        const double operator[](int i) const { return this->e[i]; } // Acceso no modificable
        double& operator[](int i){ return this->e[i]; }             // Acceso modificable
        
        const double x(){ return this->e[0]; }
        const double y(){ return this->e[1]; }
        const double z(){ return this->e[2]; }
        


                
        // suma y resta
        vec3 operator+(const vec3& other) const{
            return vec3((*this)[0] + other[0], (*this)[1] + other[1], (*this)[2] + other[2]);
        }

        vec3 operator-(const vec3& other) const{
            return vec3((*this)[0] - other[0], (*this)[1] - other[1], (*this)[2] - other[2]);
        }
        
        // vector por escalar
        vec3 operator*(const double t) const{
            return vec3((*this)[0] * t, (*this)[1] * t, (*this)[2] * t );
        }

        vec3 operator-() const { return (*this) * (-1.0); }
        vec3& operator*=(const double t) {
            this->e[0] *= t;
            this->e[1] *= t;
            this->e[2] *= t;
            return (*this);
        }

        // vector entre escalar
        vec3 operator/(const double t) const{
            return (*this) * (1/t);
        }
        vec3& operator/=(const double t) {
            return (*this) *= 1/t;
        }

        // multiplicacion escalar
        double dot(const vec3& v) const{
            return (*this)[0] * v[0] + (*this)[1] * v[1] + (*this)[2] * v[2];
        }

        // multiplicacion vectorial
        vec3 cross(const vec3&v) const{
            return vec3(
                (*this)[1] * v[2] - (*this)[2] *  v[1], // uy * vz - uz * vy
                (*this)[2] * v[0] - (*this)[0] *  v[2], // uz * vx - ux * vz
                (*this)[0] * v[1] - (*this)[1] *  v[0]  // ux * vy - uy * vx
            );
        }

        // Norma del vector
        double norm2() const{
            return (pow(this->e[0], 2) + pow(this->e[1], 2) + pow(this->e[2], 2) ); 
        }
        double norm() const { return sqrt(this->norm2()); }

        // Transform vec3 to Pixel if possible
        const Pixel to_pixel(){
            if ( this->x() < 0 || this->x() > 255 || this->y() < 0 || this->y() > 255 || this->z() < 0 || this->z() > 255 ){
                    return {0, 0, 0};
                }
            Pixel p =  { (uint)(*this)[0], (uint)(*this)[1], (uint)(*this)[2] };
            return p;
        }

};

// sysout overloading
inline std::ostream& operator<<(std::ostream& out, const vec3& v){
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

inline vec3 operator*(const double t, vec3 v){
    return  v * t;
}

inline vec3 operator/(const double t, vec3 v){
    return  v / t;
}

inline double dot(const vec3& u, const vec3& v){
    return u[0] * v[0], u[1] * v[1], u[2] * v[2];
}

inline vec3 cross(const vec3& u, const vec3& v){
    return vec3(
        u[1] * v[2] - u[2] *  v[1], // uy * vz - uz * vy
        u[2] * v[0] - u[0] *  v[2], // uz * vx - ux * vz
        u[0] * v[1] - u[1] *  v[0]  // ux * vy - uy * vx
    );
}

inline vec3 unit_vector(const vec3& u){
    return u / u.norm();
}

#endif
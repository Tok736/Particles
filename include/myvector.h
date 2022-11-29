#ifndef PARTICLES_MYVECTOR_H
#define PARTICLES_MYVECTOR_H

#include <iostream>
#include <cmath>

struct Vector {
    double x, y, z;
    Vector() : x(0), y(0), z(0) {}
    Vector(double x, double y, double z) : x(x), y(y), z(z) {}
    [[nodiscard]] double length() const;
    Vector operator+=(const Vector& other);
    Vector operator*=(const double& c);
    friend std::ostream& operator<< (std::ostream& out, const Vector& v);
};

Vector operator+(const Vector& v1, const Vector& v2);
Vector operator*(const double& c, const Vector& v);
Vector operator*(const Vector& v, const double& c);
Vector operator/(const Vector& v, const double& c);
Vector operator-(const Vector& v1, const Vector& v2);

#endif //PARTICLES_MYVECTOR_H

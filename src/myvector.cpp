#include "../include/myvector.h"

[[nodiscard]] double Vector::length() const {
    return sqrt(x * x + y * y + z * z);
}

std::ostream& operator<< (std::ostream& out, const Vector& v) {
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

Vector Vector::operator+=(const Vector &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vector Vector::operator*=(const double &c) {
    this->x *= c;
    this->y *= c;
    this->z *= c;
    return *this;
}

Vector operator+(const Vector& v1, const Vector& v2) {
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

Vector operator*(const double& c, const Vector& v) {
    return {c * v.x, c * v.y, c * v.z};
}

Vector operator*(const Vector& v, const double& c) {
    return c * v;
}

Vector operator/(const Vector& v, const double& c) {
    return v * (1 / c);
}

Vector operator-(const Vector& v1, const Vector& v2) {
    return v1 + -1 * v2;
}
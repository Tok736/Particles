#ifndef PARTICLES_RANGE_H
#define PARTICLES_RANGE_H

struct Range {
    double left, right;
    Range() = delete;
    Range(double left, double  right): left(left), right(right) {}
    [[nodiscard]] bool isOnePoint() const;
    static double rand(const Range &d);
};

#endif //PARTICLES_RANGE_H

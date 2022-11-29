#ifndef PARTICLES_BOX_H
#define PARTICLES_BOX_H

#include "range.h"
#include "myvector.h"

struct Box {
    Range xsides;
    Range ysides;
    Range zsides;
    Box(double x0, double x1, double y0, double y1, double z0, double z1);
    [[nodiscard]] bool isFixedx() const;
    [[nodiscard]] bool isFixedy() const;
    [[nodiscard]] bool isFixedz() const;
    static Vector rand(Box box);
    Box innerBox(double marginx, double marginy, double marginz);
};

#endif //PARTICLES_BOX_H

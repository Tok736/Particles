#ifndef PARTICLES_PARTICLE_H
#define PARTICLES_PARTICLE_H

#include "myvector.h"
#include "range.h"
#include "box.h"

class Particle {
private:

public:
    double mass;
    Vector pos, v;
    Particle(double mass, Vector pos, Vector v);
    void update(double elapsed);
    void force(Vector f, double elapsed);
    friend std::ostream& operator<< (std::ostream& out, const Particle& particle);
    static double distance(Particle p1, Particle p2);
    [[nodiscard]] bool isInBox(const Box& box) const;
    void returnToBox(const Box& box, double dumping);
};

Vector randVelocityInBox(Range velocity, Box box);
Particle randomParticle(Range mass, Range velocity, Box box);

#endif //PARTICLES_PARTICLE_H
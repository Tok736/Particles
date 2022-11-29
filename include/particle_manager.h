#ifndef PARTICLES_PARTICLE_MANAGER_H
#define PARTICLES_PARTICLE_MANAGER_H

#include "particle.h"
#include "array.h"
#include "box.h"
#include "myvector.h"

//const double SIZE_FACTOR = 8.31;
//const double SIZE_FACTOR = 7.9;
const double SIZE_FACTOR = 6.9;
const double FORCE_FACTOR = 56.0;
const double DUMPING = 0.2;
const double PARTICLE_M = 25.0;

class ParticleManager {
private:
    Box box;
    double sigma, eps;
    double dumping;
    double particleMass;
public:
    Array<Particle> particles;
    explicit ParticleManager(Box box);
    void update(double elapsed);
    void addForces(double elapsed);
    void addParticle(Particle p);
    void createBoxOfParticles(size_t sideAmount, const Box &innerBox);
    Box getBox();
    void addRandomParticle();
};

#endif //PARTICLES_PARTICLE_MANAGER_H

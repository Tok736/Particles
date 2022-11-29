#include "particle_manager.h"
#include <ctime>
#include <cmath>

ParticleManager::ParticleManager(Box box): box(box), sigma(SIZE_FACTOR), eps(FORCE_FACTOR), dumping(DUMPING),
                                           particleMass(PARTICLE_M) {}

void ParticleManager::update(double elapsed) {
    ParticleManager::addForces(elapsed);
    for (auto &particle : particles) {
        particle.update(elapsed);
        if (!particle.isInBox(box)) particle.returnToBox(box, dumping);
    }
}

void ParticleManager::addForces(double elapsed) {
    for (size_t i = 0; i < particles.size(); i++) {
        Vector force(0.0, 0.0, 0.0);
        for (size_t j = 0; j < particles.size(); j++) {
            Vector r21 = particles[i].pos - particles[j].pos;
            double r = r21.length();
            if (i != j) force += r21 / r * (4 * eps * (-12 * pow(sigma / r, 12) / r + 6 * pow(sigma / r, 6) / r));
        }
        particles[i].force((-1) * force, elapsed);
    }
}

void ParticleManager::addParticle(Particle p) {
    particles.push_back(p);
}

void ParticleManager::createBoxOfParticles(size_t sideAmount, const Box &innerBox) {
    double dx = (innerBox.xsides.right - innerBox.xsides.left) / (double)(sideAmount - 1);
    double dy = (innerBox.ysides.right - innerBox.ysides.left) / (double)(sideAmount - 1);
    double dz = (innerBox.zsides.right - innerBox.zsides.left) / (double)(sideAmount - 1);
    double phi = 0.3;
    double ksi = 0.2;
    double x = innerBox.xsides.right;
    for (size_t i = 0; i < sideAmount; i++) {
        double y = innerBox.ysides.right;
        for (size_t j = 0; j < sideAmount; j++) {
            double z = innerBox.zsides.right;
            for (size_t k = 0; k < sideAmount; k++) {
                double yrot = z * sin(phi) + y * cos(phi);
                double zrot = z * cos(phi) - y * sin(phi);

                double xrot = zrot * sin(ksi) + x * cos(ksi);
                zrot = zrot * cos(ksi) - x * sin(ksi);

                addParticle(Particle(particleMass, Vector(xrot, yrot, zrot), Vector(0, 0, 0)));
                z -= dz;
            }
            y -= dy;
        }
        x -= dx;
    }
}

Box ParticleManager::getBox() {
    return box;
}

void ParticleManager::addRandomParticle() {
    this->addParticle(randomParticle(Range(particleMass, particleMass), Range(0, 1.0), box));
}




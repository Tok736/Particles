#ifndef PARTICLES_ENGINE_H
#define PARTICLES_ENGINE_H

#include <SFML/Graphics.hpp>

#include "box.h"
#include "particle_manager.h"
#include "array.h"

const float MIN_PARTICLE_SIZE = 2;
const float MAX_PARTICLE_SIZE = 7;
const int MIN_BRIGHTNESS = 50;
const int MAX_BRIGHTNESS = 255;

const float Z_SIDE = 75;
const float XY_SIDE = 75;
const float BOX_SIZES[6]{-XY_SIDE, XY_SIDE, -XY_SIDE, XY_SIDE, -Z_SIDE, Z_SIDE};

const int PARTICLE_AMOUNT = 300;
const int SIDE_AMOUNT = 8;

class Engine {
private:
    size_t modeWidth, modeHeight;
    float minParticleSize, maxParticleSize;
    int minBrightness, maxBrightness;
    Box box;
    ParticleManager particleManager;
    int particleAmount;
    int sideAmount;
    double time;
    double time_for_next_particle;
    Array<sf::CircleShape> shapes_;
public:
    void convertParticlePosToShape(const Particle& p, sf::CircleShape &shape) const;
    Engine(size_t modeWidth, size_t modeHeight);
    void fillRandom();
    void fillBox();
    void update(double elapsed);
    Array<sf::CircleShape>& shapes();
};

#endif //PARTICLES_ENGINE_H

#include "engine.h"

Engine::Engine(size_t modeWidth, size_t modeHeight):
        modeWidth(modeWidth), modeHeight(modeHeight), minParticleSize(MIN_PARTICLE_SIZE), maxParticleSize(MAX_PARTICLE_SIZE),
        minBrightness(MIN_BRIGHTNESS), maxBrightness(MAX_BRIGHTNESS),
        time(0), time_for_next_particle(0),
        box(BOX_SIZES[0], BOX_SIZES[1], BOX_SIZES[2], BOX_SIZES[3], BOX_SIZES[4], BOX_SIZES[5]),
        particleManager(box), particleAmount(PARTICLE_AMOUNT), sideAmount(SIDE_AMOUNT) {}

void Engine::convertParticlePosToShape(const Particle& p, sf::CircleShape &shape) const {
    auto x = (float)((float)modeWidth * (p.pos.x - box.xsides.left) / (box.xsides.right - box.xsides.left));
    auto y = (float)((float)modeHeight * (p.pos.y - box.ysides.left) / (box.ysides.right - box.ysides.left));
    shape.setPosition(x, y);
    double znormalized = (p.pos.z - box.zsides.left) / (box.zsides.right - box.zsides.left);
    auto particleSize = (float)((maxParticleSize - minParticleSize) * znormalized + minParticleSize);
    int color = (int)(znormalized * (maxBrightness - minBrightness) + minBrightness);
    if (color < 0) color = 0;
    if (color > 255) color = 255;
    shape.setRadius(particleSize);
    shape.setFillColor(sf::Color(color, color, color));
}

void Engine::fillRandom() {
    while (particleManager.particles.size() < particleAmount) {
        particleManager.addRandomParticle();
        shapes_.push_back(sf::CircleShape(maxParticleSize));
    }
}

void Engine::fillBox() {
    particleManager.createBoxOfParticles(sideAmount, particleManager.getBox().innerBox(40, 40, 40));
    for (size_t i = 0; i < sideAmount * sideAmount * sideAmount; i++) {
        shapes_.push_back(sf::CircleShape(maxParticleSize));
    }
}

void Engine::update(double elapsed) {
    for (size_t i = 0; i < 1; i++) {
        particleManager.update(elapsed * 0.4);
    }

    time_for_next_particle -= elapsed;

    for (size_t i = 0; i < particleManager.particles.size(); i++) {
        Engine::convertParticlePosToShape(particleManager.particles[i], shapes_[i]);
    }

    time += elapsed;
}

Array<sf::CircleShape>& Engine::shapes() {
    return shapes_;
}





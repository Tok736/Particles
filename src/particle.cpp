#include "particle.h"

Particle::Particle(double mass, Vector pos, Vector v): mass(mass), pos(pos), v(v) {}

void Particle::update(double elapsed) {
    pos = pos + v * elapsed;
}

void Particle::force(Vector f, double elapsed) {
    v = v + f * (1 / mass) * elapsed;
}

std::ostream& operator<< (std::ostream& out, const Particle& p) {
    out << "[m = " << p.mass << ", pos = " << p.pos << ", v = " << p.v << "]";
    return out;
}

double Particle::distance(Particle p1, Particle p2) {
    return (p2.pos - p1.pos).length();
}

bool Particle::isInBox(const Box &box) const {
    return (pos.x > box.xsides.left && pos.x < box.xsides.right &&
            pos.y > box.ysides.left && pos.y < box.ysides.right &&
            pos.z > box.zsides.left && pos.z < box.zsides.right);
}

void Particle::returnToBox(const Box &box, double dumping) {
    if (pos.x < box.xsides.left && v.x < 0 ||
        pos.x > box.xsides.right && v.x > 0) {
        v *= dumping;
        v.x = -v.x;
    }
    if (pos.y < box.ysides.left && v.y < 0 ||
        pos.y > box.ysides.right && v.y > 0) {
        v *= dumping;
        v.y = -v.y;
    }
    if (pos.z < box.zsides.left && v.z < 0 ||
        pos.z > box.zsides.right && v.z > 0) {
        v *= dumping;
        v.z = -v.z;
    }
}

Vector randVelocityInBox(Range velocity, Box box) {
    Range r(-1, 1);
    Vector v(Range::rand(r), Range::rand(r), Range::rand(r));
    if (box.isFixedx()) v.x = 0;
    if (box.isFixedy()) v.y = 0;
    if (box.isFixedz()) v.z = 0;
    return Range::rand(velocity) * v * (1 / v.length());
}

Particle randomParticle(Range mass, Range velocity, Box box) {
    return {Range::rand(mass), Box::rand(box), randVelocityInBox(velocity, box)};
}

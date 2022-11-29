#ifndef PARTICLES_DRAWER_H
#define PARTICLES_DRAWER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "array.h"

class Drawer {
private:

public:
    Drawer();
    void draw(sf::RenderWindow &window, Array<sf::CircleShape> &shapes);
};

#endif //PARTICLES_DRAWER_H

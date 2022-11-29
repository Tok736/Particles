#include "drawer.h"


Drawer::Drawer() = default;
void Drawer::draw(sf::RenderWindow &window, Array<sf::CircleShape> &shapes) {
    window.clear();
    for (const auto &shape : shapes) {
        window.draw(shape);
    }
    window.display();
}

#include "app.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include "event_checker.h"
#include "drawer.h"
#include "engine.h"
#include "array.h"

App::App() = default;

size_t MODE_WIDTH = 900;
size_t MODE_HEIGHT = 900;

void App::run() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    sf::RenderWindow window(sf::VideoMode(MODE_WIDTH, MODE_HEIGHT), "Particles!", sf::Style::Default, settings);

    sf::Clock clock;
    EventChecker eventChecker;
    Drawer drawer;
    Engine engine(MODE_WIDTH, MODE_HEIGHT);
//    engine.fillRandom();
    engine.fillBox();

    while (window.isOpen())
    {
        float elapsed = clock.restart().asSeconds();
        eventChecker.check(window);
        engine.update(elapsed);
        drawer.draw(window, engine.shapes());
    }
}
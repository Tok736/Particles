#include "event_checker.h"

EventChecker::EventChecker() = default;

void EventChecker::check(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}


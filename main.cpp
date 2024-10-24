#include <SFML/Graphics.hpp>
#include "Playground.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(650, 400), "GamingCampus - PVZ - IA/StateMachines");
    window.setFramerateLimit(60);
    Playground* oPlayground = Playground::instantiate();
    if(!oPlayground)
    {
        return -1;
    }
    while (window.isOpen())
    {
        sf::Event event;
        sf::Event dummy_event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
            oPlayground->handleUserInput(event, window);
        }

        window.clear();
        oPlayground->draw(window);
        oPlayground->update();
        window.display();
    }

    return 0;
}
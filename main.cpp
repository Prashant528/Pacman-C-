#include "pacman.h"
#include<iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600),"PACMAN");
    sf::Texture pacTexture;
    pacTexture.loadFromFile("pac.png");
    pacmanClass pacman(&pacTexture,sf::Vector2u(2,1),0.2f,100.0f);

    float deltaTime = 0.0f;
    sf::Clock clock;
    while(window.isOpen()){
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

    pacman.Update(deltaTime);
    window.clear();
    pacman.draw(window);
    window.display();
    }
    return 0;
}

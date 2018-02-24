#include "pacman.h"
#include "villian.h"
#include "block.h"
#include<iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600),"PACMAN");
    sf::Texture pacTexture;
    pacTexture.loadFromFile("pac.png");
    pacmanClass pacman(&pacTexture,sf::Vector2u(2,1),0.2f,100.0f);

    sf::Texture gundaTexture;
    gundaTexture.loadFromFile("spike.png");
    villian gunda1(&gundaTexture, 100.0f , sf::Vector2f(700.0f,0.0f), sf::Vector2f(0.03f,0.03f));
    villian gunda2(&gundaTexture, 100.0f , sf::Vector2f(500.0f,500.0f), sf::Vector2f(0.04f,0.03f));

    sf::Texture blockTexture;
    blockTexture.loadFromFile("blocks.jpg");
    blockClass block(sf::Vector2f(200.0f,200.0f),&blockTexture);

    float deltaTime = 0.0f;
    sf::Clock clock;
    while(window.isOpen()){
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

    pacman.Update(deltaTime,window);
    gunda1.Update(deltaTime,window,block);
    gunda2.Update(deltaTime,window,block);
    window.clear();
    block.draw(window);
    pacman.draw(window);
    gunda1.draw(window);
    gunda2.draw(window);
    window.display();
    }
    return 0;
}

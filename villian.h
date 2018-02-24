#pragma once
#include<SFML/Graphics.hpp>
#include "block.h"
class villian{
private:
    sf::CircleShape enemy;
    float speed;
    sf::Vector2f change;

public:
    villian(sf::Texture* texture, float speed, sf::Vector2f position,sf::Vector2f change);
    void Update(float deltaTime,sf::RenderWindow &window,blockClass block);
    void draw(sf::RenderWindow&);
};


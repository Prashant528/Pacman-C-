#pragma once
#include<SFML/Graphics.hpp>

class villian{
private:
    sf::RectangleShape enemy;
    float speed;
    sf::Vector2f change;

public:
    villian(sf::Texture* texture, float speed, sf::Vector2f position);
    void Update(float deltaTime,sf::RenderWindow &window);
    void draw(sf::RenderWindow&);
};


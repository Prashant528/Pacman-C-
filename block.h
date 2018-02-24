#pragma once
#include<SFML/Graphics.hpp>


class blockClass{
private:
    sf::RectangleShape block;
    sf::Vector2f position;
    sf::Texture texture;

public:
    blockClass(sf::Vector2f position, sf::Texture *texture);
    void draw(sf::RenderWindow& window);
    friend class villian;
};

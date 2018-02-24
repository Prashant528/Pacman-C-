#include "block.h"

blockClass::blockClass(sf::Vector2f position, sf::Texture* texture){
    block.setPosition(position);
    block.setTexture(texture);
    block.setSize(sf::Vector2f(400.0f,200.0f));
}

void blockClass::draw(sf::RenderWindow& window){
    window.draw(block);
}

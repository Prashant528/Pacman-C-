#ifndef PACMAN_H_
#define PACMAN_H_
#include "Animation.h"
#include<SFML/Graphics.hpp>


class pacmanClass{
private:
    sf::RectangleShape head;
    Animation animation;
    int row;
    float speed;
    bool faceRight;
    sf::Texture pacTexture;
    sf::IntRect uvRect;


public:
    pacmanClass(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed);
    void Update(float deltaTime,sf::RenderWindow &window);
    void draw(sf::RenderWindow&);
};

#endif // PACMAN_H_


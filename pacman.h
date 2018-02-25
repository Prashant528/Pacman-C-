#ifndef PACMAN_H_
#define PACMAN_H_
#include "Animation.h"
#include "block.h"
#include "food.h"
#include "villian.h"
#include<SFML/Graphics.hpp>

class Food;
class villian;
class pacmanClass{
private:

    sf::RectangleShape head;
    Animation animation;
    int row;
    float speed;
    bool faceRight;
    //sf::Texture pacTexture;
    sf::IntRect uvRect;
    bool touch;


public:
    static int score;
    static int life;
    pacmanClass(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed);
    void Update(float deltaTime,sf::RenderWindow &window,blockClass winBlock);
    void draw(sf::RenderWindow&);
    friend void eaten(Food& ,pacmanClass&);
    friend void kill(villian&,pacmanClass&,sf::RenderWindow&);

  //texts down here
private:
    sf::Font font;
    sf::Text scoreText,scoreInText;
    sf::Text lifeText,lifeInText;
};

#endif // PACMAN_H_


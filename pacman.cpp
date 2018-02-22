#include "pacman.h"

pacmanClass::pacmanClass(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed):
    animation(texture,imageCount,switchTime){

    head.setSize(sf::Vector2f(50.0f,50.0f));
    head.setPosition(00.0f,00.0f);
    head.setTexture(texture);

    this->speed = speed;
    row = 0;
    faceRight=true;
}

void pacmanClass::Update(float deltaTime){
    sf::Vector2f position;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        position.x -= speed * deltaTime;

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        position.x += speed *deltaTime;
    }
    if(position.x == 0.0f){
        row = 0;
    }
    else{
        row=1;
        if(position.x >0.0f)
            faceRight = true;
        else
            faceRight = false;
    }
    animation.Update(row,deltaTime,faceRight);
    head.setTextureRect(animation.uvRect);
    head.move(position);

}

void pacmanClass::draw(sf::RenderWindow &window){
    window.draw(head);
}

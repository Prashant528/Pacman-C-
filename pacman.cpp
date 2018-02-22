#include "pacman.h"

pacmanClass::pacmanClass(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed):
    animation(texture,imageCount,switchTime){

    head.setSize(sf::Vector2f(50.0f,50.0f));
    head.setPosition(20.0f,20.0f);
    head.setTexture(texture);
    head.setOrigin(head.getSize().x/2,head.getSize().y/2);

    this->speed = speed;
    row = 0;
    faceRight=true;
}

void pacmanClass::Update(float deltaTime){
    sf::Vector2f position;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        position.x -= speed * deltaTime;
        head.setRotation(0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        position.x += speed *deltaTime;
        head.setRotation(0.f);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        position.y += speed *deltaTime;
        head.setRotation(90.f);
        if(!faceRight)
            head.setRotation(270.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        position.y -= speed *deltaTime;
        head.setRotation(270.f);
        if(!faceRight)
            head.setRotation(90.f);
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

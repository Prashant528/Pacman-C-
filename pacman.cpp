#include "pacman.h"

pacmanClass::pacmanClass(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed):
    animation(texture,imageCount,switchTime)
    {
    head.setSize(sf::Vector2f(50.0f,50.0f));
    head.setPosition(20.0f,20.0f);
    head.setTexture(texture);
    head.setOrigin(head.getSize().x/2,head.getSize().y/2);

    this->speed = speed;
    row = 0;
    faceRight=true;
}

void pacmanClass::Update(float deltaTime,sf::RenderWindow &window){
    sf::Vector2f position;

    if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(head.getPosition().x > head.getSize().x/2){
            position.x -= speed * deltaTime;
            head.setRotation(0.f);
        }
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(head.getPosition().x < window.getSize().x-head.getSize().x/2){
            position.x += speed *deltaTime;
            head.setRotation(0.f);
        }
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if(head.getPosition().y < window.getSize().y-head.getSize().y/2){
            position.y += speed *deltaTime;
            head.setRotation(90.f);
            if(!faceRight)
                head.setRotation(270.f);
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if( head.getPosition().y > head.getSize().y/2){
            position.y -= speed *deltaTime;
            head.setRotation(270.f);
            if(!faceRight)
                head.setRotation(90.f);
        }
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

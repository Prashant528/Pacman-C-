#include "pacman.h"
#include<string>
#include<stdlib.h>

pacmanClass::pacmanClass(sf::Texture* texture,sf::Vector2u imageCount,float switchTime,float speed ):
    animation(texture,imageCount,switchTime)
    {
    head.setSize(sf::Vector2f(50.0f,50.0f));
    head.setPosition(20.0f,20.0f);
    head.setTexture(texture);
    head.setOrigin(head.getSize().x/2,head.getSize().y/2);
    this->speed = speed;
    row = 0;
    faceRight=true;

    //text stuff
    font.loadFromFile("STENCIL.ttf");
    scoreText.setFont(font);
    scoreText.setString("SCORE: ");
    scoreText.setPosition(690.0f , 5.0f);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);

    scoreInText.setFont(font);
    scoreInText.setPosition(760.0f , 5.0f);
    scoreInText.setCharacterSize(20);
    scoreInText.setFillColor(sf::Color::White);

    lifeText.setFont(font);
    lifeText.setString("LIFE: ");
    lifeText.setPosition(600.0f , 5.0f);
    lifeText.setCharacterSize(20);
    lifeText.setFillColor(sf::Color::White);

    lifeInText.setFont(font);
    lifeInText.setPosition(660.0f , 5.0f);
    lifeInText.setCharacterSize(20);
    lifeInText.setFillColor(sf::Color::White);

}

void pacmanClass::Update(float deltaTime,sf::RenderWindow &window,blockClass winBlock){
    //displaying score

    char *scp;
    itoa(score,scp,10);
    scoreInText.setString(scp);
    char slife;
    char *slp=&slife;
    itoa(life,slp,10);
    lifeInText.setString(slp);

    //collision
    sf::Vector2f position;
    touch = (head.getGlobalBounds().intersects(winBlock.block.getGlobalBounds()));
    if(touch){
        if((head.getPosition().x >= winBlock.block.getPosition().x+winBlock.block.getSize().x) || (head.getPosition().y >= winBlock.block.getPosition().y+winBlock.block.getSize().y )){
            position.x += 0.05;
            position.y += 0.05;
        }
        else{
            position.x -= 0.05;
            position.y -= 0.05;
        }

    }
    else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(head.getPosition().x > head.getSize().x/2 ){
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
        //row=1;
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
    window.draw(scoreText);
    window.draw(scoreInText);
    window.draw(lifeText);
    window.draw(lifeInText);

}

#include "villian.h"
#include<ctime>

villian::villian(sf::Texture* texture, float speed,sf::Vector2f position){
    enemy.setSize(sf::Vector2f(60.0f,60.0f));
    enemy.setPosition(position);
    enemy.setTexture(texture);
    enemy.setOrigin(enemy.getSize().x/2,enemy.getSize().y/2);
    this->speed = speed;
    change =  sf::Vector2f(0.03f,0.03f);

}

void villian::Update(float deltaTime,sf::RenderWindow &window){
    sf::Vector2f pos = enemy.getPosition();
    srand(time(NULL));
    int randnum=rand()%6+1;
    if( pos.y>window.getSize().y){
        change.y *= -1;
        enemy.setPosition(pos.x-1,pos.y-1);
    }
    else if( pos.x>window.getSize().x){
        change.x *= -1;
        enemy.setPosition(pos.x-1,pos.y-1);
    }
    else if( pos.y <0){
        change.y *= -1;
        enemy.setPosition(pos.x+1,pos.y+1);
    }
    else if( pos.x <0){
        change.x *= -1;
        enemy.setPosition(pos.x+1,pos.y+1);
    }

    enemy.move(change);

}

void villian::draw(sf::RenderWindow &window){
    window.draw(enemy);
}


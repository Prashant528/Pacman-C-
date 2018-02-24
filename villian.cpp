#include "villian.h"
#include<ctime>
#include "block.h"

villian::villian(sf::Texture* texture, float speed,sf::Vector2f position,sf::Vector2f change){
    enemy.setRadius(30);
    enemy.setPosition(position);
    enemy.setTexture(texture);
    enemy.setOrigin(enemy.getRadius()/2,enemy.getRadius()/2);
    this->speed = speed;
    this->change =change;

}

void villian::Update(float deltaTime,sf::RenderWindow &window,blockClass winBlock){
    sf::Vector2f pos = enemy.getPosition();
//collision with window borders
    if( pos.y>window.getSize().y ){
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
//collision with block
    if(enemy.getGlobalBounds().intersects(winBlock.block.getGlobalBounds())){
        if( pos.y <=winBlock.block.getPosition().y  ){
            change.y *= -1;
            enemy.setPosition(pos.x-1,pos.y-1);
        }
        else if( pos.x<=winBlock.block.getPosition().x){
            change.x *= -1;
            enemy.setPosition(pos.x-1,pos.y-1);
        }
        else if( pos.y >= winBlock.block.getPosition().y + winBlock.block.getSize().y){
            change.y *= -1;
            enemy.setPosition(pos.x+1,pos.y+1);
        }
        else if( pos.x >= winBlock.block.getPosition().x + winBlock.block.getSize().x){
            change.x *= -1;
            enemy.setPosition(pos.x+1,pos.y+1);
        }
    }


    enemy.move(change);
    enemy.rotate(0.02);

}

void villian::draw(sf::RenderWindow &window){
    window.draw(enemy);
}


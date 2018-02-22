#include "maze.h"
 void maze::setBlocks(){
    for(int i=0;i<10;i++){
    blocks[i].setSize(sf::Vector2f(50.0f,50.0f));
    blocks[i].setPosition(i*50,i*50);
    blocks[i].setTexture(&blocktex);
    }
}

void maze::drawBlocks(){
    for(int i=0;i<10;i++)
            window.draw(blocks[i]);
}




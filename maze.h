#ifndef MAZE_H_
#define MAZE_H_

#include<iostream>
#include<SFML/Graphics.hpp>

class maze{
private:
    sf::RectangleShape blocks[10];
    sf::Texture blocktex;
    blocktex.loadFromFile("block2.png");


public:
    maze(){};
    void setBlocks();
    void drawBlocks();


};

#endif // MAZE_H_

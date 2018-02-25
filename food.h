#pragma once
#include<SFML/Graphics.hpp>
#include "pacman.h"
#include<vector>
class pacmanClass;

class Food{
private:                                                        //need to make the circle shape vector here !!
     sf::CircleShape food[81];
public:
    Food(int rad);
    void displayFood(sf::RenderWindow &window);
    friend void eaten(Food&,pacmanClass& );

};

#pragma once
#include<SFML/Graphics.hpp>
#include "pacman.h"
#include<vector>
#include<fstream>
class pacmanClass;

class Food{
private:                                                        //need to make the circle shape vector here !!
     std::vector<sf::CircleShape> food;
     sf::CircleShape circle;
public:
    static int foodPresent;
    Food(int rad, sf::RenderWindow& window);
    void displayFood(sf::RenderWindow &window);
    friend void eaten(Food&,pacmanClass&);


};

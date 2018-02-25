#include "food.h"

Food::Food(int rad){
    for(int i=0;i<81;i++){
        int j=60;
        food[i].setRadius(rad);
        food[i].setFillColor(sf::Color(10,200,10));
        if(i<20)
            food[i].setPosition((i+1)*j, j);
        else if(i>=20 && i<40)
            food[i].setPosition(j, ((i+1)%20)*j);
        else if(i>=40 && i<60)
            food[i-1].setPosition(((i+1)%40)*j, j+500);

    }
}


void Food::displayFood(sf::RenderWindow &window){
    for(int i=0; i<81; i++)
        window.draw(food[i]);
}


void eaten(Food& f, pacmanClass& pac){
    sf::FloatRect small = pac.head.getGlobalBounds();
    for(int i=0; i<81 ;i++){
        sf::Vector2f foodLoc = f.food[i].getPosition();
        if(small.contains(foodLoc)){
            pacmanClass::score++;

            f.food[i].setFillColor(sf::Color::Transparent);
        }
   }
}

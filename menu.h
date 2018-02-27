#pragma once
#include "SFML/Graphics.hpp"
#include "pacman.h"

const int number=4;

class Menu
{
public:
	Menu(float width, float height,sf::Texture* texture,std::string whatTodo ,std::string state,float offset,std::string score);
	~Menu();

    sf::RectangleShape background;
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	char *scpt;
	sf::Text menu[number];
	sf::Text scoreText;

};


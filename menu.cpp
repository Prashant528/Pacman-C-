
#include "Menu.h"


Menu::Menu(float width, float height,sf::Texture* texture,std::string whatTodo,std::string state,float offset,std::string score)
{
    background.setPosition(0.0,0.0);
    background.setTexture(texture);
    background.setSize(sf::Vector2f(width,height));

	font.loadFromFile("STENCIL.ttf");
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Green);
	menu[0].setString(whatTodo);
	menu[0].setCharacterSize(50);
	menu[0].setPosition(sf::Vector2f(width / 2-80, 300.0));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString(score);
	menu[1].setCharacterSize(50);
	menu[1].setPosition(sf::Vector2f(width / 2-80, 400.0));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setCharacterSize(50);
	menu[2].setPosition(sf::Vector2f(width / 2-80, 500.0));

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString(state);
	menu[3].setCharacterSize(120);
	menu[3].setPosition(sf::Vector2f(offset, 150.0));


	scpt = new char;

    itoa(pacmanClass::score,scpt,10);
    scoreText.setString(scpt);
	scoreText.setPosition(500,400);
	scoreText.setFont(font);
	scoreText.setCharacterSize(50);
	scoreText.setColor(sf::Color::White);

	selectedItemIndex = 0;
}


Menu::~Menu()
{
    delete scpt;
}

void Menu::draw(sf::RenderWindow &window)
{
    window.draw(background);
    window.draw(scoreText);
	for (int i = 0; i < number; i++)
	{
		window.draw(menu[i]);

	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < number-1)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
}

#include "pacman.h"
#include "villian.h"
#include "block.h"
#include "food.h"

int pacmanClass::score;
int pacmanClass::life=3;
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600),"PACMAN");
    sf::Texture pacTexture;
    pacTexture.loadFromFile("pac2.png");
    pacmanClass pacman(&pacTexture,sf::Vector2u(2,1),0.2f,150.0f);

    sf::Texture gundaTexture;
    gundaTexture.loadFromFile("spike.png");
    villian gunda1(&gundaTexture, 1.0f , sf::Vector2f(700.0f,0.0f), sf::Vector2f(0.03f,0.03f));
    villian gunda2(&gundaTexture, 2.0f , sf::Vector2f(500.0f,500.0f), sf::Vector2f(0.04f,0.03f));
    villian gunda3(&gundaTexture, 1.0f , sf::Vector2f(200.0f,500.0f), sf::Vector2f(-0.04f,0.02f));
    villian gunda4(&gundaTexture, 2.0f , sf::Vector2f(400.0f,100.0f), sf::Vector2f(0.04f,-0.03f));
    villian gunda5(&gundaTexture, 3.0f , sf::Vector2f(500.0f,500.0f), sf::Vector2f(-0.02f,0.03f));

    sf::Texture blockTexture;
    blockTexture.loadFromFile("blocks.jpg");
    blockClass block(sf::Vector2f(200.0f,200.0f),&blockTexture);

    Food food(5);

    int level=1;
    float deltaTime = 0.0f;
    sf::Clock clock;
    while(window.isOpen()){
        deltaTime = clock.restart().asSeconds();
        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

        pacman.Update(deltaTime,window,block);
        gunda1.Update(deltaTime,window,block);
        gunda2.Update(deltaTime,window,block);
        eaten(food,pacman);
        kill(gunda1,pacman,window);
        kill(gunda2,pacman,window);
        if(pacmanClass::life<=0){//||score is max
            pacmanClass::life =3;
            level++;
        }
        if(level==2){
            gunda3.Update(deltaTime,window,block);
            gunda4.Update(deltaTime,window,block);
            gunda5.Update(deltaTime,window,block);
            kill(gunda3,pacman,window);
            kill(gunda4,pacman,window);
            kill(gunda5,pacman,window);
        }
        window.clear();
        food.displayFood(window);
        block.draw(window);
        pacman.draw(window);
        gunda1.draw(window);
        gunda2.draw(window);
        if(level==2){
            gunda4.draw(window);
            gunda5.draw(window);
            gunda3.draw(window);
        }
        window.display();
        }
        return 0;
}

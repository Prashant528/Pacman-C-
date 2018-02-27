#include "MyWindow.h"
#include "menu.h"


void game(){
    sf::RenderWindow window(sf::VideoMode(800,600),"PACMAN");
    sf::Texture pacTexture;
    pacTexture.loadFromFile("./Images/pac2.png");
    sf::Texture heartTex;
    heartTex.loadFromFile("./Images/heart.png");
    pacmanClass pacman(&pacTexture,sf::Vector2u(2,1),0.2f,150.0f, &heartTex);

    sf::Texture gundaTexture;
    gundaTexture.loadFromFile("./Images/spike.png");
    villian gunda1(&gundaTexture, 2.0f , sf::Vector2f(700.0f,0.0f), sf::Vector2f(0.03f,0.03f));
    villian gunda2(&gundaTexture, 2.0f , sf::Vector2f(500.0f,500.0f), sf::Vector2f(0.01f,0.03f));
    villian gunda3(&gundaTexture, 2.0f , sf::Vector2f(200.0f,500.0f), sf::Vector2f(-0.02f,0.02f));
    villian gunda4(&gundaTexture, 2.0f , sf::Vector2f(400.0f,100.0f), sf::Vector2f(0.04f,-0.01f));
    villian gunda5(&gundaTexture, 2.0f , sf::Vector2f(300.0f,500.0f), sf::Vector2f(-0.02f,0.03f));

    sf::Texture blockTexture;
    blockTexture.loadFromFile("./Images/blocks.jpg");
    blockClass block(sf::Vector2f(200.0f,200.0f),&blockTexture);

    Food food1(5,window);
    Food food2(5,window);

    sf::Texture backTex;
    backTex.loadFromFile("./Images/menuTex.jpg");
    Menu *menu;
    menu =new Menu(window.getSize().x,window.getSize().y,&backTex,"Play","PACMAN",180,"HIGH SCORE");


    float deltaTime = 0.0f;
    sf::Clock clock;
    while(window.isOpen()){
        deltaTime = clock.restart().asSeconds();
        sf::Event event;

        while(window.pollEvent(event)){
            switch(event.type){

                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyReleased:
                    switch(event.key.code){
                        case sf::Keyboard::Up:
                            menu->MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu->MoveDown();
                            break;

                        case sf::Keyboard::Return:
                            std::ifstream getscore;
							sf::RenderWindow win(sf::VideoMode(300, 150), "HighScore");

							sf::Font font;
							sf::Text text;
							//sf::FloatRect bounds(text.getLocalBounds());
							sf::Event event;
                            switch (menu->GetPressedItem())
                            {
                                case 0:{
                                    pacmanClass::level=1;
                                    if(pacmanClass::life<0){
                                        window.close();
                                        pacmanClass::life=3;
                                        Food::foodPresent=68;
                                        pacmanClass::score=0;
                                        game();
                                    }
                                    break;
                                }

                                case 1:{
									getscore.open("highscore.txt");
									int x;
									getscore >> x;
									getscore.close();

									font.loadFromFile("STENCIL.ttf");
                                    char *p,s;
                                    p=&s;
                                    itoa(x,p,10);
									text.setString(p);
									text.setFont(font);
									text.setCharacterSize(36);
									text.setFillColor(sf::Color::White);

									text.setPosition(75,25);


									while (win.isOpen())
									{

										while (win.pollEvent(event))
										{
											if (event.type == sf::Event::Closed)
											{

												win.close();
												pacmanClass::life = 3;
												//game();
											}

											if (event.type == sf::Event::KeyPressed)
											{
												if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
												{
													//window.close();
													win.close();
													pacmanClass::life = 3;
													//game();
												}
											}
										}
										win.clear();
										win.draw(text);
										//win.draw(x);
										win.display();
									}
                                    break;
                                }
                                case 2:
                                    window.close();
                                    break;
                            }

                            break;
                    }

                    break;
                    }
        }

        if(pacmanClass::level==1){
            pacman.Update(deltaTime,window,block);
            gunda1.Update(deltaTime,window,block);
            gunda2.Update(deltaTime,window,block);
            gunda3.Update(deltaTime,window,block);
            eaten(food1,pacman);
            kill(gunda1,pacman,window);
            kill(gunda2,pacman,window);
            kill(gunda3,pacman,window);
            if((pacmanClass::score+1)%69 == 0){
                pacmanClass::level++;
                Food::foodPresent = 68;
                showlevel();
                //draw something(level completed
            }
            if(pacmanClass::life==0){
                Menu *tmp;
                if(tmp==NULL)//can close the window if menu can't be allocated.
                    window.close();
                tmp=new Menu(window.getSize().x,window.getSize().y,&backTex,"PLAY AGAIN","GAME OVER",110,"SCORE");
                delete menu;
                menu = tmp;
                pacmanClass::life--;


        }
        }


        else if(pacmanClass::level==2){
            pacman.Update(deltaTime,window,block);
            gunda1.Update(deltaTime,window,block);
            gunda2.Update(deltaTime,window,block);
            gunda3.Update(deltaTime,window,block);
            eaten(food2,pacman);
            kill(gunda1,pacman,window);
            kill(gunda2,pacman,window);
            kill(gunda3,pacman,window);
            gunda4.Update(deltaTime,window,block);
            gunda5.Update(deltaTime,window,block);
            kill(gunda4,pacman,window);
            kill(gunda5,pacman,window);
            if((pacmanClass::score+1)%137== 0){
                pacmanClass::level++;
            }
            if(pacmanClass::life==0 || pacmanClass::level == 3){
                Menu *tmp;
                if(tmp==NULL)
                    window.close();
                tmp=new Menu(window.getSize().x,window.getSize().y,&backTex,"Replay","GAME OVER",110,"SCORE");
                delete menu;
                menu = tmp;
                pacmanClass::life--;
        }
        }

        window.clear();
        if(pacmanClass::level==0 || pacmanClass::life<0 || pacmanClass::score ==136){
            menu->draw(window);
        }
        else if(pacmanClass::level==1){
            food1.displayFood(window);//first level ko lagi
            block.draw(window);
            pacman.draw(window);
            gunda1.draw(window);
            gunda2.draw(window);
            gunda3.draw(window);
        }
        else if(pacmanClass::level==2){
            food2.displayFood(window);//second level ko lagi
            block.draw(window);
            pacman.draw(window);
            gunda1.draw(window);
            gunda2.draw(window);
            gunda3.draw(window);
            gunda4.draw(window);
            gunda5.draw(window);

        }

        window.display();
        }
}


void showlevel()
{
	sf::RenderWindow win(sf::VideoMode(300, 150), "Congrats!");

	sf::Font font;
	font.loadFromFile("Stencil.ttf");

	sf::Text text;
	text.setString("LEVEL 2 (Press Space)");
	text.setFont(font);
	text.setCharacterSize(16);
	text.setFillColor(sf::Color::White);
	sf::FloatRect bounds(text.getLocalBounds());
	text.setPosition(win.getSize().x / 2 - (bounds.left + bounds.width / 2), win.getSize().y / 2 - (bounds.top + bounds.height / 2));


	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				//window.close();
				win.close();
				//pacmanClass::life = 3;
				//game();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					//window.close();
					win.close();
					//pacmanClass::life = 3;
					//game();
				}

			}
		}
		win.clear();
		win.draw(text);
		win.display();
	}
}




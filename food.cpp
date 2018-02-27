#include "food.h"

Food::Food(int rad,sf::RenderWindow& window){//parameter for food


     for(unsigned int i=0;i<68;i++){
        food.push_back(circle);
    }


        int x1 = 200;
        int x2 = 400;
        int a, b;
        for (int j = 0; j<2; j++)
        {
            b = x1 - (j + 1) * 40;
            for (int i = 0; i<11; i++)
            {
                a = x1 + i * 40;
                food[i+j*22].setPosition(a, b);
                food[i+j*22].setRadius(rad);
                food[i+j*22].setFillColor(sf::Color(10,200,10));

            }
            b = x2 + (j + 1) * 40;
            for (int i = 0; i<11; i++)
            {
                a = x1 + i * 40;
                food[j * 22 + 11 + i].setPosition(a, b);
                food[j*22+i+11].setRadius(rad);
                food[j*22+i+11].setFillColor(sf::Color(10,200,10));

            }

        }

		x1 = 200;
		x2 = 600;
		a = 0;
		b = 0;
		for (int j = 0; j<2; j++)
		{
			b = x1 - (j + 1) * 40;
			for (int i = 0; i<6; i++)
			{
				a = x1 + i * 40;
				food[i + 44 + j * 12].setPosition(b, a);
				food[i + 44 + j * 12].setRadius(rad);
				food[i + 44 + j * 12].setFillColor(sf::Color(10, 200, 10));

			}
			b = x2 + (j + 1) * 40;
			for (int i = 0; i<6; i++)
			{
				a = x1 + i * 40;
				food[j * 12 + i + 50].setPosition(b, a);
				food[j * 12 + i + 50].setRadius(rad);
				food[j * 12 + i + 50].setFillColor(sf::Color(10, 200, 10));

			}

		}

}



void Food::displayFood(sf::RenderWindow &window){
    for(int i=0; i< Food::foodPresent; i++)
       window.draw(food[i]);
}


void eaten(Food& f, pacmanClass& pac){
    sf::FloatRect small = pac.head.getGlobalBounds();
    for(unsigned int i=0; i< f.food.size() ;i++){
        sf::Vector2f foodLoc = f.food[i].getPosition();
        if(small.contains(foodLoc)){
            pacmanClass::score++;
            f.food[i].setFillColor(sf::Color::Transparent);
            f.food.erase(f.food.begin()+i);
            Food::foodPresent--;
            if(pacmanClass::score==68){
            pac.head.setPosition(20.0f,20.0f);
            }
        }
   }

   std::ifstream infile;
   int x;
   infile.open("highscore.txt");
   infile >>x;
   infile.close();
   std::ofstream outfile("highscore.txt");

   if(pacmanClass::score > x){
    outfile << pacmanClass::score;

   }
   else
    outfile << x;
   outfile.close();
}

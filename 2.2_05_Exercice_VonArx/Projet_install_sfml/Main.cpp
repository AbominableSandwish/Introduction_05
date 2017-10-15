#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <cmath>
#include <ctime>
#include "Shapes.h"

#define HEIGHT_WINDOW 500
#define WIDTH_WINDOW 500


int circle_pos_x = 0;
int circle_pos_y = 0;

int main(){
	Shapes* s1 = new Rectangle(WIDTH_WINDOW / 2 , HEIGHT_WINDOW / 2, 100, 100);
	Shapes* s2 = new Circle(6.0, 5.0, 3.0);
	sf::ContextSettings settings;
	settings.antialiasingLevel = 30;
	// cr�ation de la fen�tre
	sf::RenderWindow window(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "M_project", sf::Style::Default, settings);
	// on fait tourner le programme tant que la fen�tre n'a pas �t� ferm�e
	while (window.isOpen()){
		// effacement de la fen�tre en noir
		window.clear(sf::Color::Black);
		window.setFramerateLimit(30);
		dynamic_cast<Circle*>(s2)->setPosition((sf::Mouse::getPosition(window).x-50), (sf::Mouse::getPosition(window).y)-50);
			// on traite tous les �v�nements de la fen�tre qui ont �t� g�n�r�s depuis la derni�re it�ration de la boucle
			sf::Event event;
			while (window.pollEvent(event))
			{
				// fermeture de la fen�tre lorsque l'utilisateur le souhaite
				if (event.type == sf::Event::Closed){
					window.close();
				}
			}
			if (s1->isColliding(s2))
			{
				dynamic_cast<Circle*>(s2)->sh_circle.setFillColor(sf::Color::Red);
				dynamic_cast<Rectangle*>(s1)->sh_rectangle.setFillColor(sf::Color::Red);
			}
			else
			{
				dynamic_cast<Circle*>(s2)->sh_circle.setFillColor(sf::Color(100, 250, 50));
				dynamic_cast<Rectangle*>(s1)->sh_rectangle.setFillColor(sf::Color::Blue);
			}
			window.draw(dynamic_cast<Rectangle*>(s1)->sh_rectangle);
			window.draw(dynamic_cast<Circle*>(s2)->sh_circle);
			window.display();
	}
	delete s1;
	delete s2;
	return 0;
}


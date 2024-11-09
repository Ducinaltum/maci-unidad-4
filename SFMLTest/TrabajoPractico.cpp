//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Crosshair.h"
#include "Minigame.h"
#include "Drag.h"
#include "Splats.h"
#include "Atrapado.h"
#include "Adaptacion.h"
#include "Clickale.h"

using namespace sf;

int main()
{
sf:RenderWindow App(sf::VideoMode(800, 600, 32), "TP Número 4");
	Minigame* activeGame;
	activeGame = new Crosshair(App.getSize());
	App.clear();
	App.display();
	while (App.isOpen())
	{
		Event evt;
		while (App.pollEvent(evt))
		{
			switch (evt.type)
			{
			case sf::Event::Closed:
				App.close();
				break;
			case sf::Event::KeyPressed:
				if (evt.key.code == sf::Keyboard::Num1)
				{
					delete activeGame;
					activeGame = new Crosshair(App.getSize());
					App.clear();
					App.display();
				}
				else if (evt.key.code == sf::Keyboard::Num2)
				{
					delete activeGame;
					activeGame = new Drag(&App);
					App.clear();
					App.display();
				}
				else if (evt.key.code == sf::Keyboard::Num3)
				{
					delete activeGame;
					activeGame = new Splats();
					App.clear();
					App.display();
				}
				else if (evt.key.code == sf::Keyboard::Num4)
				{
					delete activeGame;
					activeGame = new Atrapado();
					App.clear();
					App.display();
				}
				else if (evt.key.code == sf::Keyboard::Num5)
				{
					delete activeGame;
					activeGame = new Adaptacion();
					App.clear();
					App.display();
				}
				else if (evt.key.code == sf::Keyboard::Num6)
				{
					delete activeGame;
					activeGame = new Clickale(&App, 5);
					App.clear();
					App.display();
				}
				break;
			}
		}

		activeGame->Update(&App);
	}
	return 0;
}
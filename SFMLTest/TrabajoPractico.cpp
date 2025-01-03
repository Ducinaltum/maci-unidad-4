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
	RenderWindow App(sf::VideoMode(800, 600, 32), "Crosshair");
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
					App.setTitle("Crosshair");
					activeGame = new Crosshair(App.getSize());
					App.clear();
					App.display();
				}
				else if (evt.key.code == sf::Keyboard::Num2)
				{
					delete activeGame;
					App.setTitle("Drag");
					activeGame = new Drag(&App);
					App.clear();
					App.display();
				}
				else if (evt.key.code == sf::Keyboard::Num3)
				{
					delete activeGame;
					App.setTitle("Splats");
					activeGame = new Splats(&App);
					App.clear();
					App.display();
				}
				else if (evt.key.code == sf::Keyboard::Num4)
				{
					delete activeGame;
					App.setTitle("Atrapado");
					activeGame = new Atrapado();
					App.clear();
					App.display();
				}
				else if (evt.key.code == sf::Keyboard::Num5)
				{
					delete activeGame;
					App.setTitle("Adaptacion");
					activeGame = new Adaptacion();
					App.clear();
					App.display();
				}
				else if (evt.key.code == sf::Keyboard::Num6)
				{
					delete activeGame;
					App.setTitle("Clickale");
					activeGame = new Clickale(&App, 5);
					App.clear();
					App.display();
				}
				break;
			}
		}
		App.clear();
		activeGame->Update(&App);
		App.display();
	}
	return 0;
}
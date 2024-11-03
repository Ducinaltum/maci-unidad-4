//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Crosshair.h"
#include "Minigame.h"
#include "Drag.h"
#include "Splats.h"

using namespace sf;

int main()
{
	sf:RenderWindow App(sf::VideoMode(800, 600, 32), "TP Número 4");
	Minigame * activeGame;
	//activeGame = new Crosshair(App.getSize());
	//activeGame = new Drag(&App);
	activeGame = new Splats();

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
			}
		}

		activeGame->Update(&App);
	}
	return 0;
}
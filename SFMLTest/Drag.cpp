#include "Drag.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Drag::Drag(RenderWindow* app)
{
	rw = app;
	sniper = new Texture();
	sniper->loadFromFile("rcircle.png");

	for (int i = 0; i < 4; i++)
	{
		snipers[i] = new Sprite();
		snipers[i]->setTexture(*sniper);
	}
	snipers[1]->setPosition(rw->getSize().x - sniper->getSize().x, 0);
	snipers[2]->setPosition(0, rw->getSize().y - sniper->getSize().y);
	snipers[3]->setPosition(rw->getSize().x - sniper->getSize().x, rw->getSize().y - sniper->getSize().y);
}

void Drag::Update(RenderWindow* app)
{
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		sf::Vector2i localPosition = sf::Mouse::getPosition(*rw);
		if (grabbedPoint == -1)
		{
			for (int i = 0; i < NUMBER_OF_SNIPERS; i++)
			{
				FloatRect spriteRect = snipers[i]->getGlobalBounds();
				Vector2f floatingPosition(localPosition.x, localPosition.y);
				if (spriteRect.contains(floatingPosition))
				{
					grabbedPoint = i;
					offset = floatingPosition - snipers[grabbedPoint]->getPosition();
				}
			}
		}
		else
		{
			snipers[grabbedPoint]->setPosition(localPosition.x - offset.x, localPosition.y - offset.y);
		}
	}
	else
	{
		grabbedPoint = -1;
	}
	app->clear();
	for (int i = 0; i < NUMBER_OF_SNIPERS; i++)
	{
		app->draw(*snipers[i]);
	}
	app->display();
}
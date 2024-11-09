#include "Adaptacion.h"

Adaptacion::Adaptacion()
{
	minScreenSize = new Vector2i(100, 100);
	maxScreenSize = new Vector2i(1000, 1000);
}

Adaptacion::~Adaptacion()
{
	delete minScreenSize;
	delete maxScreenSize;
}

void Adaptacion::Update(RenderWindow* app)
{
	if (sf::Event::Resized)
	{
		Vector2u newSize(app->getSize());
		if (app->getSize().x < minScreenSize->x)
		{
			newSize.x = minScreenSize->x;
		}
		else if (app->getSize().x > maxScreenSize->x)
		{
			newSize.x = maxScreenSize->x;
		}
		if (app->getSize().y < minScreenSize->y)
		{
			newSize.y = minScreenSize->y;
		}
		else if (app->getSize().y > maxScreenSize->y)
		{
			newSize.y = maxScreenSize->y;
		}
		app->setView(sf::View(sf::FloatRect(0, 0, newSize.x, newSize.y)));
		app->setSize(newSize);
	}
}

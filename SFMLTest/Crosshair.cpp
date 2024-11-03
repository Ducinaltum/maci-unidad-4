#include "Crosshair.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Crosshair::Crosshair(Vector2u screenSize)
{
	sCrosshair = new Sprite();
	Texture* tCrosshair = new Texture();
	tCrosshair->loadFromFile("crosshair.png");
	sCrosshair->setTexture(*tCrosshair);
	sCrosshair->setOrigin(tCrosshair->getSize().x / 2, tCrosshair->getSize().y / 2);
	sCrosshair->setPosition(screenSize.x / 2, screenSize.y / 2);
}

void Crosshair::Update(RenderWindow* app)
{
	app->draw(*sCrosshair);
}

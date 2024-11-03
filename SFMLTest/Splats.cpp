#include "Splats.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;


Splats::Splats()
{
	hasClicked = false;
	sprite = new Sprite();
	redCircle = new Texture();
	blueCircle = new Texture();
	redCircle->loadFromFile("rcircle.png");
	blueCircle->loadFromFile("rcircleb.png");
}

void Splats::Update(RenderWindow* app)
{
	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		if (!hasClicked)
		{
			DrawSprite(app, redCircle);
		}
	}
	else if (Mouse::isButtonPressed(Mouse::Button::Right))
	{
		if (!hasClicked)
		{
			DrawSprite(app, blueCircle);
		}
	}
	else
	{
		hasClicked = false;
	}
}

void Splats::DrawSprite(RenderWindow* app, Texture* tex)
{
	hasClicked = true;
	sf::Vector2i localPosition = sf::Mouse::getPosition(*app);
	sprite->setTexture(*tex);
	sprite->setOrigin(tex->getSize().x / 2, tex->getSize().y / 2);
	sprite->setPosition(localPosition.x, localPosition.y);
	app->draw(*sprite);
	app->display();
}

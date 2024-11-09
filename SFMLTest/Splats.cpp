#include "Splats.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;


Splats::Splats(RenderWindow* app)
{
	sprite = new Sprite();
	redCircle = new Texture();
	blueCircle = new Texture();
	redCircle->loadFromFile("rcircle.png");
	blueCircle->loadFromFile("rcircleb.png");
	texture = new RenderTexture();
	texture->create(app->getSize().x, app->getSize().y);
}

Splats::~Splats()
{
	delete sprite;
	delete redCircle;
	delete blueCircle;
	delete texture;
}

void Splats::Update(RenderWindow* app)
{
	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		DrawSprite(app, redCircle);
	}
	else if (Mouse::isButtonPressed(Mouse::Button::Right))
	{
		DrawSprite(app, blueCircle);
	}
	app->draw(*new Sprite(texture->getTexture()));
}

void Splats::DrawSprite(RenderWindow* app, Texture* tex)
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(*app);
	sprite->setTexture(*tex);
	sprite->setOrigin(tex->getSize().x / 2, tex->getSize().y / 2);
	sprite->setPosition(localPosition.x, localPosition.y);
	texture->draw(*sprite);
	texture->display();
}

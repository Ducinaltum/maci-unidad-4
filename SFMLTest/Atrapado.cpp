#include "Atrapado.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Atrapado::Atrapado()
{
	sprite = new Sprite();
	squareTex = new Texture();
	circleTex = new Texture();
	squareTex->loadFromFile("cuad_yellow.png");
	circleTex->loadFromFile("rcircle.png");
	sprite->setTexture(*squareTex);
	spriteSize = new Vector2f(128, 128);
	spritePos = new Vector2f(0, 0);
	speed = 0.1;
	isSquare = false;
	isSpacePressed = false;
	SwapTexture();
}

Atrapado::~Atrapado()
{
	delete sprite;
	delete squareTex;
	delete circleTex;
	delete spriteSize;
	delete spritePos;
}

void Atrapado::SwapTexture()
{
	isSquare = !isSquare;
	if (isSquare)
	{
		sprite->setTexture(*squareTex);
		Vector2f ratio(spriteSize->x / squareTex->getSize().x, spriteSize->y / squareTex->getSize().y);
		sprite->setScale(ratio);
	}
	else
	{
		sprite->setTexture(*circleTex);
		Vector2f ratio(spriteSize->x / circleTex->getSize().x, spriteSize->y / circleTex->getSize().y);
		sprite->setScale(ratio);
	}
}

float Atrapado::Clamp(float current, float min, float max)
{
	if (current < min)
		return min;
	if (current > max)
		return max;
	return current;
}

void Atrapado::Update(RenderWindow* app)
{
	Vector2f input(0,0);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		input.x -= 1;
	if(Keyboard::isKeyPressed(Keyboard::Key::Right))
		input.x += 1;
	if(Keyboard::isKeyPressed(Keyboard::Key::Up))
		input.y -= 1;
	if(Keyboard::isKeyPressed(Keyboard::Key::Down))
		input.y += 1;
	if (Keyboard::isKeyPressed(Keyboard::Key::Space))
	{
		if (!isSpacePressed)
		{
			SwapTexture();
		}
		isSpacePressed = true;
	}
	else
	{
		isSpacePressed = false;
	}

	spritePos->x += input.x * speed,
	spritePos->y += input.y * speed;
	Vector2f screenLimits(app->getSize().x - spriteSize->x, app->getSize().y - spriteSize->y);
	spritePos->x = Clamp(spritePos->x, 0, screenLimits.x);
	spritePos->y = Clamp(spritePos->y, 0, screenLimits.y);

	sprite->setPosition(spritePos->x, spritePos->y);

	app->draw(*sprite);
}
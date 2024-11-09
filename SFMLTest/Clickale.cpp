#include "Clickale.h"
#include <random>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Clickale::Clickale(RenderWindow* app, int enemiesToKill)
{
	srand(time(NULL));
	crosshair = new Sprite();
	enemy = new Sprite();
	crosshairTex = new Texture();
	enemyTex = new Texture();
	crosshairTex->loadFromFile("crosshair.png");
	enemyTex->loadFromFile("et.png");
	crosshair->setTexture(*crosshairTex);
	enemy->setTexture(*enemyTex);
	crosshairTargetSize = new Vector2f(64, 64);
	enemyTargetSize = new Vector2f(192, 192);
	crosshair->setScale(crosshairTargetSize->x / crosshairTex->getSize().x, crosshairTargetSize->y / crosshairTex->getSize().y);
	enemy->setScale(enemyTargetSize->x / enemyTex->getSize().x, enemyTargetSize->y / enemyTex->getSize().y);
	crosshairOffset = new Vector2f(crosshairTargetSize->x / 2, crosshairTargetSize->y / 2);
	enemiesRemaining = enemiesToKill;
	SetEnemyPosition(app->getSize());
}

Clickale::~Clickale()
{
	delete crosshair;
	delete enemy;
	delete crosshairTex;
	delete enemyTex;
	delete crosshairOffset;
	delete crosshairTargetSize;
	delete enemyTargetSize;
}

void Clickale::Update(RenderWindow* app)
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(*app);
	if (enemiesRemaining > 0)
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			FloatRect spriteRect = enemy->getGlobalBounds();
			Vector2f floatingPosition(localPosition.x, localPosition.y);
			if (spriteRect.contains(floatingPosition))
			{
				enemiesRemaining--;
				SetEnemyPosition(app->getSize());
			}
		}
	}
	crosshair->setPosition(localPosition.x - crosshairOffset->x, localPosition.y - crosshairOffset->y);
	if (enemiesRemaining > 0)
		app->draw(*enemy);
	app->draw(*crosshair);
}

void Clickale::SetEnemyPosition(Vector2u screenSize)
{
	int newXPos = rand() % (int)(screenSize.x - enemyTargetSize->x);
	int newYPos = rand() % (int)(screenSize.y - enemyTargetSize->y);
	enemy->setPosition(newXPos, newYPos);
}

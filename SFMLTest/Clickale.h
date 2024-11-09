#pragma once
#include "Minigame.h"
class Clickale : public Minigame
{
private:
	Sprite* crosshair;
	Sprite* enemy;
	Texture* crosshairTex;
	Texture* enemyTex;
	Vector2f* crosshairOffset;
	Vector2f* crosshairTargetSize;
	Vector2f* enemyTargetSize;
	int enemiesRemaining;
public:
	Clickale(RenderWindow* app, int enemiesToKill);
	void Update(RenderWindow* app) override;
	void SetEnemyPosition(Vector2u screenSize);
};


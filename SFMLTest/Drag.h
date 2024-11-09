#pragma once
#include "Minigame.h"
class Drag : public Minigame
{
private:
	const int NUMBER_OF_SNIPERS = 4;
	RenderWindow* rw;
	Sprite* snipers[4]; //Se puede asignar NUMBER_OF_SNIPERS en este punto?
	Texture* sniper;
	int grabbedPoint = -1;
	Vector2f offset;

public:
	Drag(RenderWindow* app);
	~Drag();
	void Update(RenderWindow* app) override;
};


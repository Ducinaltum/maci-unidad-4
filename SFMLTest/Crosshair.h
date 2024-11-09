#pragma once
#include "Minigame.h"

class Crosshair: public Minigame
{
private:
	Sprite* sCrosshair;
	Texture* tCrosshair;
public:
	Crosshair(Vector2u screenSize);
	~Crosshair();
	void Update(RenderWindow* App)  override;
};


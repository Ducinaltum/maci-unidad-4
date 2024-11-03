#pragma once
#include "Minigame.h"

class Crosshair: public Minigame
{
private:
	Sprite* sCrosshair;
public:
	Crosshair(Vector2u screenSize);
	void Update(RenderWindow* App)  override;
};


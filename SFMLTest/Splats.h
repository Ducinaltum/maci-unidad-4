#pragma once
#include "Minigame.h"
class Splats : public Minigame
{
private:
	Sprite* sprite;
	Texture* redCircle;
	Texture* blueCircle;
	void DrawSprite(RenderWindow* app, Texture* tex);

public:
	Splats();
	void Update(RenderWindow* app) override;
};


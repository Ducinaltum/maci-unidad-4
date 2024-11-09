#pragma once
#include "Minigame.h"

class Splats : public Minigame
{
private:
	Sprite* sprite;
	Texture* redCircle;
	Texture* blueCircle;
	RenderTexture *texture;
	void DrawSprite(RenderWindow* app, Texture* tex);

public:
	Splats(RenderWindow* app);
	~Splats();
	void Update(RenderWindow* app) override;
};


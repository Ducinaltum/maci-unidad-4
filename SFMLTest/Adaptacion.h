#pragma once
#include "Minigame.h"
class Adaptacion : public Minigame
{
private:
	Vector2i* minScreenSize;
	Vector2i* maxScreenSize;
public:
	Adaptacion();
	~Adaptacion();
	void Update(RenderWindow* app) override;
};


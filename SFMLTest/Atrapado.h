#pragma once
#include "Minigame.h"
class Atrapado : public Minigame
{
private:
	Sprite* sprite;
	Texture *squareTex;
	Texture *circleTex;
	Vector2f * spriteSize;
	Vector2f* spritePos;
	bool isSquare;
	float speed;
	bool isSpacePressed;
	void SwapTexture();
	float Clamp(float current, float min, float max);
public:
	Atrapado();
	~Atrapado();
	void Update(RenderWindow* app) override;
};


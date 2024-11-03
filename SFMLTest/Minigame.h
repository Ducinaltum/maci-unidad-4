#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class Minigame
{
public:
	virtual void Update(RenderWindow* App) = 0;
};


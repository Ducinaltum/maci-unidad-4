#include "Splats.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;


Splats::Splats(RenderWindow* app)
{
	sprite = new Sprite();
	redCircle = new Texture();
	blueCircle = new Texture();
	redCircle->loadFromFile("rcircle.png");
	blueCircle->loadFromFile("rcircleb.png");
	texture = new RenderTexture();
	texture->create(app->getSize().x, app->getSize().y);
}

Splats::~Splats()
{
	delete sprite;
	delete redCircle;
	delete blueCircle;
	delete texture;
}


//Por favor, revisar el commit "Splat odd behaviour" - 86d72798729553f99d0fe466349692cd9d64cc71 
//No entiendo por que tiene ese comportamiento tan extraño, parece como si guardara dos buffer independientes,
//Me pareció bastante curioso y me gustaría saber el porqué
void Splats::Update(RenderWindow* app)
{
	// Clear the whole texture with red color
	// Draw stuff to the texture

	// We're done drawing to the texture
	//texture.display();

	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		DrawSprite(app, redCircle);
	}
	else if (Mouse::isButtonPressed(Mouse::Button::Right))
	{
		DrawSprite(app, blueCircle);
	}
	app->draw(*new Sprite(texture->getTexture()));
}

void Splats::DrawSprite(RenderWindow* app, Texture* tex)
{
	sf::Vector2i localPosition = sf::Mouse::getPosition(*app);
	sprite->setTexture(*tex);
	sprite->setOrigin(tex->getSize().x / 2, tex->getSize().y / 2);
	sprite->setPosition(localPosition.x, localPosition.y);
	//app->draw(*sprite);
	texture->draw(*sprite);
	texture->display();
}

#include "Player.h"

Player::Player(Vector2u imageCount, float switchTime, float speed)
{
	this->speed = speed;
	row = 0;

	playerTexture.loadFromFile("Textures/merfolk.png");
	body.setTexture(&playerTexture);
	body.setSize(Vector2f(120.f, 100.f));
	body.setPosition(450.f, 300.f);
	uvRect.width = playerTexture.getSize().x / 3;
	uvRect.height = playerTexture.getSize().y / 4;
	body.setTextureRect(IntRect(0, 0, uvRect.width, uvRect.height));

	animationFrame = 0;
}

Player::~Player()
{
}

void Player::Update()
{
	ptime = pclock.getElapsedTime().asMilliseconds();
	time = clock.getElapsedTime().asMilliseconds();
	Vector2f movement(0.f, 0.f);

	if (Keyboard::isKeyPressed(Keyboard::A) && body.getPosition().x > 0 && ptime > 5)
	{
		pclock.restart();
		body.move(-1.75f, 0.f);
		body.setTextureRect(IntRect(uvRect.width * animationFrame, uvRect.height * 1, uvRect.width, uvRect.height));
	}
	if (Keyboard::isKeyPressed(Keyboard::D) && body.getPosition().x < 950 && ptime > 5)
	{
		pclock.restart();
		body.move(1.75f, 0.f);
		body.setTextureRect(IntRect(uvRect.width * animationFrame, uvRect.height * 2, uvRect.width, uvRect.height));
	}
	if (sf::Keyboard::isKeyPressed(Keyboard::W) && body.getPosition().y > 200 && ptime > 5)
	{
		pclock.restart();
		body.move(0.f, -1.75f);
		body.setTextureRect(IntRect(uvRect.width * animationFrame, uvRect.height * 3, uvRect.width, uvRect.height));
	}
	if (sf::Keyboard::isKeyPressed(Keyboard::S) && body.getPosition().y < 600 && ptime > 5)
	{
		pclock.restart();
		body.move(0.f, 1.75f);
		body.setTextureRect(IntRect(uvRect.width * animationFrame, uvRect.height * 0, uvRect.width, uvRect.height));
	}
	if (time > 100)
	{
		animationFrame++;
		clock.restart();
	}

	if (animationFrame >= 3)
	{
		animationFrame = 0;
	}

	body.move(movement);
	
}

void Player::Draw(RenderWindow& window)
{
	window.draw(body);
}

#include "Item.h"

int randItem(int start, int stop) {
	int n = (rand() % (stop - start + 1)) + start;
	return int(n);
}

Item::Item()
{
	shieldTexture.loadFromFile("Textures/shield.png");
	shield.setSize(Vector2f(40.f, 45.f));
	shield.setPosition(randItem(100, 940), randItem(200, 575));
	shield.setTexture(&shieldTexture);

	bubbleTexture.loadFromFile("Textures/bubble.png");
	bubble.setSize(Vector2f(125.f, 125.f));
	bubble.setTexture(&bubbleTexture);

	healTexture.loadFromFile("Textures/heal.png");
	heal.setSize(Vector2f(40.f, 45.f));
	heal.setPosition(randItem(100, 940), randItem(200, 575));
	heal.setTexture(&healTexture);

	bonusTexture.loadFromFile("Textures/bonus.png");
	bonus.setSize(Vector2f(40.f, 40.f));
	bonus.setPosition(randItem(100, 940), randItem(200, 575));
	bonus.setTexture(&bonusTexture);
}

Item::~Item()
{
}

void Item::Draw(RenderWindow& window)
{
	if (shieldState)
	{
		window.draw(shield);
	}
	if (bubbleState)
	{
		window.draw(bubble);
	}
	if (healState)
	{
		window.draw(heal);
	}
	if (bonusState)
	{
		window.draw(bonus);
	}
}

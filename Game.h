#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Background.h"
#include "Coin.h"
#include "Enemy.h"
#include "Animation.h"
#include "Item.h"
using namespace sf;
using namespace std;

class Game
{
public:
	Game();
	~Game();
	
	void CoinCollision();
	void ItemCollision();
	void SharkCollision();
	void ScoreUpdate();
	void HpUpdate();
	void Update();
	void GameOver();
	void Draw(RenderWindow& window);

private:
	Player player;
	RectangleShape hpBar;
	RectangleShape hpBarBack;
	
	Coin coin;
	Font fontScore;
	Text score;
	size_t point;

	Enemy enemy;
	
	Item item;

	Background background;

	float deltaTime = 0.0f;
	Clock clock;

};


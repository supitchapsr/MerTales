#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "Coin.h"
#include "Enemy.h"
#include "Animation.h"
#include "Babyshark.h"
#include "Specialshark.h"
#include "Item.h"
#include "Song.h"
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
	void BabyCollision();
	void BossCollision();
	void ScoreUpdate();
	void HpUpdate();
	void SpeedUpdate();
	void DrawGameOver();
	bool GameOver();
	void Reset();
	void Draw(RenderWindow& window);

private:
	Event event;
	Font font;

	Player player;
	Coin coin[10];
	Enemy enemy;
	Babyshark babyshark;
	Specialshark specialshark;
	Item item;
	Song song;
	Background background;

	RectangleShape hpBar;
	RectangleShape hpBarBase;
	int hp;
	Text score;
	size_t point;
	RectangleShape bg;
	Texture bgTexture;

	RectangleShape quit;
	Texture quitTexture;

	Text gameOver;
	Text yourScore;
	Text press;
	Texture overTexture;
	RectangleShape overbox;

	Texture userTexture;
	RectangleShape userbox;
	string userName;
	vector<char> name;
	Text user;

	Clock shieldClock;
	long shieldTime;
	Clock bubbleClock;
	long bubbleTime;
	Clock healClock;
	long healTime;
	Clock bonusClock;
	long bonusTime;
};


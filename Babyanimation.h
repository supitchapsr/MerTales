#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Babyanimation
{
public:
	Babyanimation(Vector2u imageCount, float switchTime);
	~Babyanimation();

	void Update(int row, float time, bool faceRight);

	IntRect uvRect;

private:
	Vector2u imageCount;
	Vector2u currentImage;
	Texture sharkTexture;

	float totalTime;
	float switchTime;
};


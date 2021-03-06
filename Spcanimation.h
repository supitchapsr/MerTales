#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Spcanimation
{
public:
	Spcanimation(Vector2u imageCount, float switchTime);
	~Spcanimation();

	void Update(int row, float time, bool faceRight);

	IntRect uvRect;

private:
	Vector2u imageCount;
	Vector2u currentImage;
	Texture spcTexture;

	float totalTime;
	float switchTime;
};


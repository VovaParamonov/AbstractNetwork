#pragma once
class Point
{
public:
	float posX;
	float posY;

	float speedX;
	float speedY;

	bool checked = false;

	Point();
	Point(float newPosX, float newPosY, float newSpeedX, float newSpeedY);

	void move(int width, int height);
};


#include "Point.h"
#include "math.h"

Point::Point()
{
	posX = 10;
	posY = 10;

	speedX = 0.01;
	speedY = 0.01;
}

Point::Point(float newPosX, float newPosY, float newSpeedX, float newSpeedY)
{
	posX = newPosX;
	posY = newPosY;

	speedX = newSpeedX;
	if (speedX == 0) speedX = 0.2;
	
	speedY = newSpeedY;
	if (speedY == 0) speedY = 0.2;
}

void Point::move(int width, int height) {
	this->posX += this->speedX;
	this->posY += this->speedY;

	if (posX > width || posX < 0) {
		posX = width - posX;
	}

	if (posY > height || posY < 0) {
		posY = height - posY;
	}	
}
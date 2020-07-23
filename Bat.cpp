#include "Bat.h"

Bat::Bat(float startX, float startY)
{
	mPosition.x = startX;
	mPosition.y = startY;

	mShape.setSize(sf::Vector2f(50, 5));
	mShape.setPosition(mPosition);

}

sf::FloatRect Bat::getPosition()
{
	return mShape.getGlobalBounds();
}

sf::RectangleShape Bat::getShape()
{
	return mShape;
}

void Bat::moveLeft()
{
	mMovingLeft = true;
}

void Bat::moveRight()
{
	mMovingRight = true;
}

void Bat::stopLeft()
{
	mMovingLeft = false;
}

void Bat::stopRight()
{
	mMovingRight = false;
}

void Bat::update(sf::Time dt)
{
	if (mMovingLeft)
	{
		mPosition.x -= mSpeed * dt.asSeconds();
	}

	if (mMovingRight)
	{
		mPosition.x += mSpeed * dt.asSeconds();
	}
	mShape.setPosition(mPosition);
}
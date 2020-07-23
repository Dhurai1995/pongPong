#include "Ball.h"

Ball::Ball(float startX, float startY)
{
	mPosition.x = startX;
	mPosition.y = startY;

	mShape.setSize(sf::Vector2f(10, 10));
	mShape.setPosition(mPosition);
}

sf::FloatRect Ball::getPosition()
{
	return mShape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape()
{
	return mShape;
}

float Ball::getXVelocity()
{
	return mDirectionX;
}

void Ball::reboudSides()
{
	mDirectionX = -mDirectionX;
}

void Ball::reboudBatOrTop()
{
	mDirectionY = -mDirectionY;
}

void Ball::reboundBottom()
{
	mPosition.x = 500;
	mPosition.y = 0;
	mDirectionY = -mDirectionY;
}

void Ball::update(sf::Time dt)
{
	mPosition.x += mDirectionX *  mSpeed * dt.asSeconds();
	mPosition.y += mDirectionY * mSpeed * dt.asSeconds();
	mShape.setPosition(mPosition);
}
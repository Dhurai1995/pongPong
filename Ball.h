#pragma once
#include<SFML\Graphics.hpp>

class Ball
{
private:
	sf::Vector2f mPosition;
	sf::RectangleShape mShape;

	float mSpeed = 300.0f;
	float mDirectionX = .2f;
	float mDirectionY = .2f;

public:

	Ball(float startX, float startY);
	sf::FloatRect getPosition();
	sf::RectangleShape getShape();
	float getXVelocity();
	void reboudSides();
	void reboudBatOrTop();
	void reboundBottom();
	void update(sf::Time dt);

};
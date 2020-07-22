#pragma once
#include<SFML\Graphics.hpp>

class Bat

{
	sf::Vector2f mPosition;

	float mSPeed = 1000.0f;

	bool mMovingRight = false;
	bool mMovingLeft = false;

public:

	Bat(float StartX, float StartY);

	sf::FloatRect getPosition();

	sf::RectangleShape getShape();

	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();

	void update(sf::Time dt);

};
// The main file of the pong game
#include<iostream>
#include<sstream>
#include "Bat.h"
#include<cstdlib>
#include<SFML\Graphics.hpp>
#include "Ball.h"

int main()
{
	sf::VideoMode vm(1920, 1080);

	sf::RenderWindow window(vm, "Pong", sf::Style::Fullscreen);
	
	int score = 0;
	int lives = 3;

	Bat bat(1920 / 2, 1080 - 20);
	Ball ball(1920 / 2, 0);

	sf::Text hud;

	sf::Font font;
	font.loadFromFile("fonts/ka1.ttf");
	
	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(sf::Color::White);
	hud.setPosition(20, 20);
	sf::Clock clock;

	while (window.isOpen())
	{
		/*
		Handle the players input
		*/

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			bat.moveLeft();
		else
			bat.stopLeft();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			bat.moveRight();
		else
			bat.stopRight();

		/*
		Update the bat, the ball and the HUD
		*/

		sf::Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);
		std::stringstream ss;
		ss << "Score: " << score << "Lives:" << lives;
		hud.setString(ss.str());

		/* 
		draw the bat, ball and the hud
		*/
		window.clear();
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.display();
	}
	return 0;
}
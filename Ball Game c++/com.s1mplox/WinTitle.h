#pragma once

#include <sstream>

#include "Player.h"
#include "Ball.h"
#include "Goal.h"

class WinTitle
{
private:
	sf::Font font;
	sf::Text text;
	sf::Color colorRed;
	sf::Color colorBlue;


	sf::String whoWin;
	sf::Vector2f velocity; //predkosc tego napisu

public:
	WinTitle();
	~WinTitle();

	void setVelocity(float x, float y)
	{
		this->velocity = sf::Vector2f(x, y);
	}

	sf::Vector2f getVelocity() const { return this->velocity; }
	



	void titleSet(sf::Color color, std::string whoWin);

	void update(float& deltatime);
	void render(sf::RenderWindow& target);
};


#pragma once

#include "Player.h"

class Scorebar
{
private:
	sf::Sprite* spr;
	sf::Texture txt;

	void initVariables();
	void setScoreBar();

public:
	Scorebar();
	~Scorebar();

	void render(sf::RenderWindow& window);
};


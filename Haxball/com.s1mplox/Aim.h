#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include "Collision.h"

class Aim
{
private:
	
	bool detectVertex(Ball &f_ball, Player &f_player);
	Collision col;
	

public:
	sf::Vertex pointsOfLine[2];
	sf::Vector2f point;


	void setPoint(Ball& f_ball);
	sf::Vector2f getPoint() const;

	    Aim();
		~Aim();

	void render(sf::RenderWindow& window);
	void update(float deltatime, sf::RenderTarget& target, Ball& f_ball, Player& f_player);
	
};


#pragma once

#include "Player.h"

class Goal
{
private:
	sf::RectangleShape shape[2];
	const float goalWidth = 20.f;
	const float goalHeight = 109.f;


	void initVariables();
	void setLinesPosition();
	
public:
	Goal();
	~Goal();

	void render(sf::RenderWindow& window);

	sf::RectangleShape getShape(int i) const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getOrigin() const;
	float getLeftSideGoal_LEFT() const;
	float getRightSideGoal_LEFT() const;
	float getLeftSideGoal_RIGHT() const;
	float getRightSideGoal_RIGHT() const;
};


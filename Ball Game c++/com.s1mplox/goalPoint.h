#pragma once

#include "Player.h"


class goalPoint
{
private:
	sf::CircleShape point;

	void initVariables();

public:
	goalPoint();
	~goalPoint();


	void draw(sf::RenderWindow *window);
	void update(float& deltatime, sf::RenderTarget* target);

	//Settery
	void setPosition(float x, float y);

	//Gettery
	sf::Vector2f getPosition() const;
	float getRadius() const;

};


#pragma once

#include "Player.h"

class Stakes
{
private:
	sf::CircleShape stake[4];


	void initVariables();
	void setStakes();
	void setVelocity(float a, float b);

	sf::Vector2f velocity;
	float mass;
	float radius;

public:
	Stakes();
	~Stakes();

	


	void render(sf::RenderWindow &window);
	

	sf::Vector2f getPosition() const;
	sf::Vector2f getVelocity() const;
	sf::CircleShape getShape(int i) const;
	

	float getRadius() const;
	float getMass() const;

};


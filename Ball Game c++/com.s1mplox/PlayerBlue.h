#pragma once

#include "SFML/Graphics.hpp"
#include "Stakes.h"



#include <iostream>

class PlayerBlue
{
public:
	PlayerBlue(std::string nickname, sf::Color colorPlayer, float x, float y);
	~PlayerBlue();


	void updateRed(float deltatime, sf::RenderTarget* target);
	void updateBlue(float deltatime, sf::RenderTarget* target);
	void draw(sf::RenderWindow* window);

	//settery
	void setAcceleration(float x, float y);
	void setVelocity(float x, float y);
	void setVecVelocityGoal(float x, float y);
	void setPosition(float x, float y);
	void setOutlineColor(sf::Color color);



	//gettery
	float Approach(float flGoal, float flCurrent, float dt);
	float getMass() const;
	float getRadius() const;
	sf::Vector2f getOrigin() const;
	sf::Vector2f getAcceleration() const;
	sf::Vector2f getVelocity() const;
	sf::Vector2f getVecVelocityGoal() const;
	sf::Vector2f getPosition() const;
	sf::FloatRect getGlobalBounds() const;
	sf::Color getOutlineColor() const;
	sf::CircleShape getShape() const;

	sf::Vector2f acceleration;
	sf::Vector2f velocity;
	sf::Vector2f vecVelocityGoal;
	sf::Color OutlineColor;


private:

	sf::CircleShape shape;
	sf::Color colorPlayer;

	std::string nickname;

	float x, y;

	float radius;
	float mass;
	double angle;



	void initVariables();


};



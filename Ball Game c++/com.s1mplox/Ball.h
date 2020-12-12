#pragma once



#include "SFML/Graphics.hpp"
#include "Player.h"
#include "PlayerBlue.h"
#include "goalPoint.h"
#include "goalPointBlue.h"
#include <iostream>

class Ball
{
private:

	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::CircleShape circleShape; 
	

	float mass;
	float radius;
	float x, y;

	void initVariables();

public:
	Ball();
	~Ball();

	sf::Vector2f currVelocity;
	float maxSpeed;

	//Direction ball

	sf::Vector2f vertexDirBall;
	sf::Vector2f playerCenter;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;


	void update(float deltatime, sf::RenderTarget &target, sf::RenderWindow& win, Ball& f_ball, Player& f_player, PlayerBlue &f_player2, goalPoint& g_point, goalPointBlue& g_point2);
	void draw(sf::RenderWindow& window); //rysowanie na ekranie

	//settery
	void setVelocity(float x, float y); //predkosc
	void setAcceleration(float x, float y); //przyspieszenie
	void setPosition(float x, float y);

	//gettery
	sf::Vector2f getVelocity() const;
	sf::Vector2f getAcceleration() const;
	sf::Vector2f getOrigin() const;
	float getMass() const;
	float getRadius() const;
	sf::Vector2f getPosition() const;
	sf::CircleShape getShape() const;
	float getRightSideBall() const;
	float getLeftSideBall() const;

};


#include "Ball.h"
#include "Collision.h"
#include "Aim.h"
#include "hitBoxMap.h"


void Ball::initVariables()
{
	this->radius = 10.f;
	this->mass = (radius * 20.f);
	this->x = 463.f;
	this->y = 215.f;
	this->currVelocity = { 0.f, 0.f };
	this->maxSpeed = 10.0f;

}

Ball::Ball()
{
	this->initVariables();

	circleShape.setFillColor(sf::Color::White);
	circleShape.setRadius(radius);
	circleShape.setOrigin(radius, radius);
	circleShape.setPosition(sf::Vector2f(x, y));
	circleShape.setOutlineColor(sf::Color::Black);
	circleShape.setOutlineThickness(2.f);

}

Ball::~Ball(){}

void Ball::update(float deltatime, sf::RenderTarget& target, sf::RenderWindow &win, Ball& f_ball, Player& f_player, PlayerBlue& f_player2, goalPoint& g_point, goalPointBlue& g_point2)
{
	Collision col;

	setAcceleration(-getVelocity().x * 0.9f * deltatime, -getVelocity().y * 0.9f * deltatime); //Zwolnienie
	setVelocity(getVelocity().x + (getAcceleration().x), getVelocity().y + (getAcceleration().y)); //predkosc

	//Red Player

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		f_player.setOutlineColor(sf::Color::White);

		if (col.ballOverPlayer(f_ball, f_player))
		{
			
			this->vertexDirBall = sf::Vector2f(g_point.getPosition().x, g_point.getPosition().y);
			this->playerCenter = sf::Vector2f(f_player.getPosition().x + f_player.getRadius(), f_player.getPosition().y + f_player.getRadius());
			this->aimDir = this->vertexDirBall - this->playerCenter;
			this->aimDirNorm = this->aimDir / sqrt(pow(this->aimDir.x, 2) + pow(this->aimDir.y, 2));

			currVelocity = this->aimDirNorm * f_ball.maxSpeed;

			setVelocity(currVelocity.x, currVelocity.y);
			
		}
		else {
			setAcceleration(-getVelocity().x * 0.9f * deltatime, -getVelocity().y * 0.9f * deltatime); //Zwolnienie
			setVelocity(getVelocity().x + (getAcceleration().x), getVelocity().y + (getAcceleration().y)); //predkosc
		}
	}
		else {
			f_player.setOutlineColor(sf::Color::Black);
		}

	//Blue Player

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		f_player2.setOutlineColor(sf::Color::White);

		if (col.ballOverPlayer(f_ball, f_player2))
		{

			this->vertexDirBall = sf::Vector2f(g_point2.getPosition().x, g_point2.getPosition().y);
			this->playerCenter = sf::Vector2f(f_player2.getPosition().x + f_player2.getRadius(), f_player2.getPosition().y + f_player2.getRadius());
			this->aimDir = this->vertexDirBall - this->playerCenter;
			this->aimDirNorm = this->aimDir / sqrt(pow(this->aimDir.x, 2) + pow(this->aimDir.y, 2));

			currVelocity = this->aimDirNorm * f_ball.maxSpeed;

			setVelocity(currVelocity.x, currVelocity.y);

		}
		else {
			setAcceleration(-getVelocity().x * 0.9f * deltatime, -getVelocity().y * 0.9f * deltatime); //Zwolnienie
			setVelocity(getVelocity().x + (getAcceleration().x), getVelocity().y + (getAcceleration().y)); //predkosc
		}
	}
	else {
		f_player2.setOutlineColor(sf::Color::Black);
	}



		hitBoxMap map;

		//Zrobic to inaczej tak jak, ball.cpp i goal.cpp

		//LEFT UP
		if (this->circleShape.getGlobalBounds().intersects(map.getBox(4).getGlobalBounds()))
		velocity.x = -getVelocity().x;
		
		//LEFT DOWN
		else if (this->circleShape.getGlobalBounds().intersects(map.getBox(5).getGlobalBounds()))
		velocity.x = -getVelocity().x;
		

		//UP
		else if (this->circleShape.getGlobalBounds().intersects(map.getBox(6).getGlobalBounds()))
		velocity.y = -getVelocity().y;

		//RIGHT UP
		else if (this->circleShape.getGlobalBounds().intersects(map.getBox(7).getGlobalBounds()))
		velocity.x = -(getVelocity().x);

		//RIGHT DOWN
		else if (this->circleShape.getGlobalBounds().intersects(map.getBox(8).getGlobalBounds()))
		velocity.x = -(getVelocity().x);

		//DOWN
		else if (this->circleShape.getGlobalBounds().intersects(map.getBox(9).getGlobalBounds()))
		velocity.y = -(getVelocity().y);

		//FOR GOAL LEFT TOP
		else if (this->circleShape.getGlobalBounds().intersects(map.getBox(12).getGlobalBounds()))
		velocity.y = 0.1f;

		//FOR GOAL LEFT BOTTOM
		else if (this->circleShape.getGlobalBounds().intersects(map.getBox(13).getGlobalBounds()))
		velocity.y = -0.1f;

		//FOR GOAL RIGHT TOP
		else if (this->circleShape.getGlobalBounds().intersects(map.getBox(14).getGlobalBounds()))
		velocity.y = 0.1f;

		//FOR GOAL RIGHT BOTTOM
		else if (this->circleShape.getGlobalBounds().intersects(map.getBox(15).getGlobalBounds()))
		velocity.y = -0.1f;

		//FOR GOAL LEFT
		else if (this->circleShape.getGlobalBounds().intersects(map.getBox(10).getGlobalBounds()))
		velocity.x = 0.1f;

		//FOR GOAL RIGHT
		else if (this->circleShape.getGlobalBounds().intersects(map.getBox(11).getGlobalBounds()))
		velocity.x = -0.1f;

		else {
			setAcceleration(-getVelocity().x * 0.9f * deltatime, -getVelocity().y * 0.9f * deltatime); //Zwolnienie
			setVelocity(getVelocity().x + (getAcceleration().x), getVelocity().y + (getAcceleration().y)); //predkosc
		}

		circleShape.move(getVelocity());

	
}


void Ball::draw(sf::RenderWindow& window)
{
	window.draw(circleShape);
}


float Ball::getRadius() const
{
	return circleShape.getRadius();
}

sf::Vector2f Ball::getPosition() const
{
	return circleShape.getPosition();
}

sf::CircleShape Ball::getShape() const
{
	return this->circleShape;
}

float Ball::getRightSideBall() const
{
	return this->circleShape.getPosition().x + this->circleShape.getRadius();
}

float Ball::getLeftSideBall() const
{
	return this->circleShape.getPosition().x - this->circleShape.getRadius();
}

void Ball::setVelocity(float x, float y)
{
	this->velocity = sf::Vector2f(x, y);
}

void Ball::setAcceleration(float x, float y)
{
	this->acceleration = sf::Vector2f(x, y);
}

void Ball::setPosition(float x, float y)
{
	this->circleShape.setPosition(sf::Vector2f(x, y));
}

float Ball::getMass() const
{
	return mass;
}

sf::Vector2f Ball::getVelocity() const
{
	return velocity;
}

sf::Vector2f Ball::getAcceleration() const
{
	return acceleration;
}

sf::Vector2f Ball::getOrigin() const
{
	return this->circleShape.getOrigin();
}

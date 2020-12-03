#include "Stakes.h"



void Stakes::initVariables()
{
	this->radius = 8.f;
	
	for (auto& i : this->stake)
	{
		i.setFillColor(sf::Color(255, 204, 204));
		i.setOutlineColor(sf::Color::Black);
		i.setOutlineThickness(2.f);
		i.setRadius(radius);
		i.setOrigin(radius, radius);
	}
	
	
	this->velocity = sf::Vector2f(0.f, 0.f);
}

void Stakes::setStakes()
{
	//slupki lewe
	this->stake[0].setPosition(sf::Vector2f(89.f, 151.f));
	this->stake[1].setPosition(sf::Vector2f(89.f, 278.f));
	//this->stake[1].setPosition(sf::Vector2f(120.f, 269.f));

	//slupki prawe
	this->stake[2].setPosition(sf::Vector2f(836.f, 151.f));
	this->stake[3].setPosition(sf::Vector2f(836.f, 278.f));
}


Stakes::Stakes()
{
	
	

	this->initVariables();
	this->setStakes();
}

Stakes::~Stakes()
{
}




void Stakes::setVelocity(float a, float b)
{
	this->velocity = sf::Vector2f(a, b);
}


void Stakes::render(sf::RenderWindow& window)
{
	for (auto& i : this->stake)
	{
		window.draw(i);
	}
}

sf::Vector2f Stakes::getPosition() const
{
	for (auto& i : this->stake)
	{
		return i.getPosition();
	}
}

sf::Vector2f Stakes::getVelocity() const
{
	return this->velocity;
}

sf::CircleShape Stakes::getShape(int i) const
{
	return this->stake[i];
}





float Stakes::getRadius() const
{
	for (auto& i : this->stake)
	{
		return i.getRadius();
	}
}

float Stakes::getMass() const
{
	return this->mass;
}

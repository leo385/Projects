#include "goalPointBlue.h"



void goalPointBlue::initVariables()
{
	this->point.setFillColor(sf::Color::Transparent);
	this->point.setOutlineColor(sf::Color::Transparent);
	this->point.setOutlineThickness(1.f);
	this->point.setRadius(1.f);
}

goalPointBlue::goalPointBlue()
{
	this->initVariables();

}

goalPointBlue::~goalPointBlue()
{
}



void goalPointBlue::draw(sf::RenderWindow* window)
{
	window->draw(this->point);
}

void goalPointBlue::update(float& deltatime, sf::RenderTarget* target)
{

}

void goalPointBlue::setPosition(float x, float y)
{
	this->point.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f goalPointBlue::getPosition() const
{
	return this->point.getPosition();
}

float goalPointBlue::getRadius() const
{
	return this->point.getRadius();
}

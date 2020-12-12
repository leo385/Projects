#include "goalPoint.h"

void goalPoint::initVariables()
{
	this->point.setFillColor(sf::Color::Transparent);
	this->point.setOutlineColor(sf::Color::Transparent);
	this->point.setOutlineThickness(1.f);
	this->point.setRadius(1.f);
}

goalPoint::goalPoint()
{
	this->initVariables();

}

goalPoint::~goalPoint()
{
}



void goalPoint::draw(sf::RenderWindow* window)
{
	window->draw(this->point);
}

void goalPoint::update(float &deltatime, sf::RenderTarget* target)
{

}

void goalPoint::setPosition(float x, float y)
{
	this->point.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f goalPoint::getPosition() const
{
	return this->point.getPosition();
}

float goalPoint::getRadius() const
{
	return this->point.getRadius();
}

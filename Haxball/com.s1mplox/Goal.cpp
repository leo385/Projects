#include "Goal.h"

void Goal::initVariables()
{
	for (auto& i : this->shape)
	{
		i.setFillColor(sf::Color::Transparent);
		i.setSize(sf::Vector2f(this->goalWidth, this->goalHeight));
		i.setOrigin(this->goalWidth / 2.f, this->goalHeight / 2.f);
	}
}

void Goal::setLinesPosition()
{
	this->shape[0].setPosition(sf::Vector2f(70.f, 220.f));
	this->shape[1].setPosition(sf::Vector2f(855.f, 220.f));

}


Goal::Goal()
{
	this->initVariables();
	this->setLinesPosition();
}

Goal::~Goal()
{
}



void Goal::render(sf::RenderWindow& window)
{
	for(auto& i : this->shape)
	window.draw(i);
}

sf::RectangleShape Goal::getShape(int i) const
{
	return this->shape[i];
}

sf::Vector2f Goal::getPosition() const
{
	for (auto& i : this->shape)
		return i.getPosition();
}

sf::Vector2f Goal::getOrigin() const
{
	return this->shape->getOrigin();
}

float Goal::getLeftSideGoal_LEFT() const
{
		return this->shape[0].getPosition().x - this->shape[0].getSize().x / 2.f;
}

float Goal::getRightSideGoal_LEFT() const
{
	    return this->shape[0].getPosition().x + this->shape[0].getSize().x / 2.f;
}

float Goal::getLeftSideGoal_RIGHT() const
{
	return this->shape[1].getPosition().x - this->shape[0].getSize().x / 2.f;
}

float Goal::getRightSideGoal_RIGHT() const
{
	return this->shape[1].getPosition().x + this->shape[0].getSize().x / 2.f;
}

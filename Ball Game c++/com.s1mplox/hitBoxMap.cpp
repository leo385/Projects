#include "hitBoxMap.h"

void hitBoxMap::initVariables()
{
	for (auto& i : this->box)
	{
		i.setFillColor(sf::Color::Transparent);

	}

}

void hitBoxMap::setBoxes()
{

	//border screen lines collision for the players

	//LEFT
	this->box[0].setPosition(sf::Vector2f(30.f, 10.f));
	this->box[0].setSize(sf::Vector2f(5.f, 400.f));


	//UP
	this->box[1].setPosition(sf::Vector2f(35.f, 10.f));
	this->box[1].setSize(sf::Vector2f(850.f, 5.f));
	
	//RIGHT
	this->box[2].setPosition(sf::Vector2f(885.f, 10.f));
	this->box[2].setSize(sf::Vector2f(5.f, 400.f));

	//DOWN
	this->box[3].setPosition(sf::Vector2f(35.f, 405.f));
	this->box[3].setSize(sf::Vector2f(850.f, 5.f));

	//border pitch lines for the ball

	//tym sie zajmiemy/////////////////////////////////////////////////////////

	//LEFT UP
	this->box[4].setPosition(sf::Vector2f(91.f, 44.f));
	this->box[4].setSize(sf::Vector2f(4.f, 100.f));

	//LEFT DOWN

	this->box[5].setPosition(sf::Vector2f(91.f, 286.f));
	this->box[5].setSize(sf::Vector2f(4.f, 99.f));

	//UP
	this->box[6].setPosition(sf::Vector2f(91.f, 44.f));
	this->box[6].setSize(sf::Vector2f(743.f, 4.f));

	//RIGHT UP
	this->box[7].setPosition(sf::Vector2f(831.f, 44.f));
	this->box[7].setSize(sf::Vector2f(4.f, 100.f));

	//RIGHT DOWN
	this->box[8].setPosition(sf::Vector2f(831.f, 286.f));
	this->box[8].setSize(sf::Vector2f(4.f, 101.f));

	//DOWN
	this->box[9].setPosition(sf::Vector2f(91.f, 383.f));
	this->box[9].setSize(sf::Vector2f(744.f, 4.f));


	/////////////////////////////////////////////////////////////////////
	//FOR GOAL LEFT
	this->box[10].setPosition(sf::Vector2f(60.f, 150.f));
	this->box[10].setSize(sf::Vector2f(4.f, 129.f));

	//FOR GOAL RIGHT
	this->box[11].setPosition(sf::Vector2f(861.f, 150.f));
	this->box[11].setSize(sf::Vector2f(4.f, 129.f));

	//LEFT TOP GOAL BAR
	this->box[12].setPosition(sf::Vector2f(60.f, 150.f));
	this->box[12].setSize(sf::Vector2f(20.f, 4.f));

	//LEFT BOTTOM GOAL BAR
	this->box[13].setPosition(sf::Vector2f(60.f, 277.f));
	this->box[13].setSize(sf::Vector2f(20.f, 4.f));

	//RIGHT TOP GOAL BAR
	this->box[14].setPosition(sf::Vector2f(845.f, 150.f));
	this->box[14].setSize(sf::Vector2f(20.f, 4.f));

	//RIGHT BOTTOM GOAL BAR
	this->box[15].setPosition(sf::Vector2f(845.f, 277.f));
	this->box[15].setSize(sf::Vector2f(20.f, 4.f));




	

}

hitBoxMap::hitBoxMap()
{
	this->initVariables();
	this->setBoxes();
}

hitBoxMap::~hitBoxMap()
{
}

sf::Vector2f hitBoxMap::getPosition() const
{
	for (auto& i : this->box)
	{
		return i.getPosition();
	}
}

sf::FloatRect hitBoxMap::getGlobalBounds() const
{
	for (auto& i : this->box)
	{
		return i.getGlobalBounds();
	}
}

sf::RectangleShape hitBoxMap::getBox(int i) const
{
	return this->box[i];
}

float hitBoxMap::getLeftUpWall() const
{
	return this->box[4].getPosition().x + this->box[4].getSize().x / 2.f;
}

float hitBoxMap::getLeftDownWall() const
{
	return this->box[5].getPosition().x + this->box[5].getSize().x / 2.f;
}

float hitBoxMap::getUpWall() const
{
	return this->box[6].getPosition().y + this->box[6].getSize().y / 2.f;
}

float hitBoxMap::getDownWall() const
{
	return this->box[9].getPosition().y - this->box[9].getSize().y / 2.f;
}

float hitBoxMap::getRightUpWall() const
{
	return this->box[7].getPosition().x - this->box[7].getSize().x / 2.f;
}

float hitBoxMap::getRightDownWall() const
{
	return this->box[8].getPosition().x - this->box[8].getSize().x / 2.f;
}







void hitBoxMap::render(sf::RenderWindow &window)
{
	for (auto& i : this->box)
	{
		window.draw(i);
	}

	
}

#include "Scorebar.h"

void Scorebar::initVariables()
{
	this->txt.loadFromFile("Sprite/score_bar.png");
	this->spr = new sf::Sprite(txt);

}

void Scorebar::setScoreBar()
{
	this->spr->setScale(0.75f, 0.75f);
	this->spr->setPosition(sf::Vector2f(300.f, -0.05f));
}

Scorebar::Scorebar()
{
	this->initVariables();
	this->setScoreBar();
}

Scorebar::~Scorebar()
{
	delete spr;
}

void Scorebar::render(sf::RenderWindow& window)
{
	window.draw(*this->spr);
}

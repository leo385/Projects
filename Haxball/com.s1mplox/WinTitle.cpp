#include "WinTitle.h"


WinTitle::WinTitle()
{
	
}

WinTitle::~WinTitle()
{
	
}

void WinTitle::titleSet(sf::Color color, std::string whoWin)
{
	this->whoWin = whoWin;


	std::stringstream ss;
	ss << whoWin;

	this->font.loadFromFile("Font/arial.ttf");
	this->text.setFont(font);
	this->text.setCharacterSize(35);
	this->text.setFillColor(color);
	this->text.setOutlineColor(color);
	this->text.setPosition(sf::Vector2f(380.f, 50.f));
	this->text.setOutlineThickness(1.f);
	this->text.setString(ss.str());
}


void WinTitle::update(float& deltatime)
{

}

void WinTitle::render(sf::RenderWindow& target)
{
	target.draw(text);
}

#pragma once



#include "Player.h"



class hitBoxMap
{
private:

	//Koniec mapy
	sf::RectangleShape box[16];

	void initVariables();
	void setBoxes();

public:
	hitBoxMap();
	~hitBoxMap();

	sf::Vector2f getPosition() const;
	sf::FloatRect getGlobalBounds() const;
	sf::RectangleShape getBox(int i) const;
	

	void render(sf::RenderWindow &window);


};


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
	

	float getLeftUpWall() const;
	float getLeftDownWall() const;
	float getUpWall() const;
	float getDownWall() const;
	float getRightUpWall() const;
	float getRightDownWall() const;

	void render(sf::RenderWindow &window);


};


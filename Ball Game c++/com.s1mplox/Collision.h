#pragma once

#include "SFML/Graphics.hpp"

#include "Ball.h"
#include "Player.h"
#include "PlayerBlue.h"
#include "hitBoxMap.h"
#include "Stakes.h"
#include "Goal.h"
#include "goalPoint.h"

class Collision
{
public:
	Collision();
	~Collision();

	bool ballOverPlayer(Ball& ball, Player& player); //Czy nasz³o na siebie


	bool ballOverPlayerBLUE(Ball& ball, PlayerBlue& playerblue);

	bool playerOverPlayer(Player& player_1, PlayerBlue& player_2);
	

	//Player Red
	bool l_UpStakeOverPlayer(Stakes& stake, Player& player);
	bool l_DownStakeOverPlayer(Stakes& stake, Player& player);
	bool r_UpStakeOverPlayer(Stakes& stake, Player& player);
	bool r_DownStakeOverPlayer(Stakes& stake, Player& player);

	//Player Blue
	bool l_UpStakeOverPlayerBlue(Stakes& stake, PlayerBlue& player);
	bool l_DownStakeOverPlayerBlue(Stakes& stake, PlayerBlue& player);
	bool r_UpStakeOverPlayerBlue(Stakes& stake, PlayerBlue& player);
	bool r_DownStakeOverPlayerBlue(Stakes& stake, PlayerBlue& player);


	//For Ball
	bool l_UpStakeOverBall(Stakes& stake, Ball& ball);
	bool l_DownStakeOverBall(Stakes& stake, Ball& ball);
	bool r_UpStakeOverBall(Stakes& stake, Ball& ball);
	bool r_DownStakeOverBall(Stakes& stake, Ball& ball);


	float distanceSquared(sf::Vector2f a, sf::Vector2f b); //Zwracanie odleg³oœci kwadratowej

};


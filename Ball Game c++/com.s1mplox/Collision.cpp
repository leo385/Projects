#include "Collision.h"


Collision::Collision()
{
}

Collision::~Collision()
{
}

bool Collision::ballOverPlayer(Ball& ball, Player& player)
{
	float distance = distanceSquared(ball.getPosition(), player.getPosition());
	float radiusSum = ball.getRadius() + player.getRadius();	

	return distance <= radiusSum * radiusSum; //z twierdzenia pitagorasa zwraca true jesli dystans jest mniejszy lub rowny sumie promieni kulek
}

bool Collision::ballOverPlayerBLUE(Ball& ball, PlayerBlue& playerblue)
{
	float distanceBLUE = distanceSquared(ball.getPosition(), playerblue.getPosition());
	float radiusSumBLUE = ball.getRadius() + playerblue.getRadius();

	return distanceBLUE <= radiusSumBLUE * radiusSumBLUE;
}

bool Collision::playerOverPlayer(Player& player_1, PlayerBlue& player_2)
{
	float distance = distanceSquared(player_1.getPosition(), player_2.getPosition());
	float radiusSum = player_1.getRadius() + player_2.getRadius();

	return distance <= radiusSum * radiusSum;
}


bool Collision::l_UpStakeOverPlayer(Stakes& stake, Player& player)
{
	
		float distance = distanceSquared(stake.getShape(0).getPosition(), player.getPosition());
		float radiusSum = stake.getShape(0).getRadius() + player.getRadius();



		return distance <= radiusSum * radiusSum;
	
}

bool Collision::l_DownStakeOverPlayer(Stakes& stake, Player& player)
{

	float distance = distanceSquared(stake.getShape(1).getPosition(), player.getPosition());
	float radiusSum = stake.getShape(1).getRadius() + player.getRadius();



	return distance <= radiusSum * radiusSum;

}

bool Collision::r_UpStakeOverPlayer(Stakes& stake, Player& player)
{

	float distance = distanceSquared(stake.getShape(2).getPosition(), player.getPosition());
	float radiusSum = stake.getShape(2).getRadius() + player.getRadius();



	return distance <= radiusSum * radiusSum;

}

bool Collision::r_DownStakeOverPlayer(Stakes& stake, Player& player)
{

	float distance = distanceSquared(stake.getShape(3).getPosition(), player.getPosition());
	float radiusSum = stake.getShape(3).getRadius() + player.getRadius();



	return distance <= radiusSum * radiusSum;

}

bool Collision::l_UpStakeOverPlayerBlue(Stakes& stake, PlayerBlue& player)
{
	float distance = distanceSquared(stake.getShape(0).getPosition(), player.getPosition());
	float radiusSum = stake.getShape(0).getRadius() + player.getRadius();



	return distance <= radiusSum * radiusSum;
}

bool Collision::l_DownStakeOverPlayerBlue(Stakes& stake, PlayerBlue& player)
{
	float distance = distanceSquared(stake.getShape(1).getPosition(), player.getPosition());
	float radiusSum = stake.getShape(1).getRadius() + player.getRadius();



	return distance <= radiusSum * radiusSum;
}

bool Collision::r_UpStakeOverPlayerBlue(Stakes& stake, PlayerBlue& player)
{
	float distance = distanceSquared(stake.getShape(2).getPosition(), player.getPosition());
	float radiusSum = stake.getShape(2).getRadius() + player.getRadius();



	return distance <= radiusSum * radiusSum;
}

bool Collision::r_DownStakeOverPlayerBlue(Stakes& stake, PlayerBlue& player)
{
	float distance = distanceSquared(stake.getShape(3).getPosition(), player.getPosition());
	float radiusSum = stake.getShape(3).getRadius() + player.getRadius();



	return distance <= radiusSum * radiusSum;
}

bool Collision::l_UpStakeOverBall(Stakes& stake, Ball& ball)
{
	float distance = distanceSquared(stake.getShape(0).getPosition(), ball.getPosition());
	float radiusSum = stake.getShape(0).getRadius() + ball.getRadius();



	return distance <= radiusSum * radiusSum;
}

bool Collision::l_DownStakeOverBall(Stakes& stake, Ball& ball)
{
	float distance = distanceSquared(stake.getShape(1).getPosition(), ball.getPosition());
	float radiusSum = stake.getShape(1).getRadius() + ball.getRadius();



	return distance <= radiusSum * radiusSum;
}

bool Collision::r_UpStakeOverBall(Stakes& stake, Ball& ball)
{
	float distance = distanceSquared(stake.getShape(2).getPosition(), ball.getPosition());
	float radiusSum = stake.getShape(2).getRadius() + ball.getRadius();



	return distance <= radiusSum * radiusSum;
}

bool Collision::r_DownStakeOverBall(Stakes& stake, Ball& ball)
{
	float distance = distanceSquared(stake.getShape(3).getPosition(), ball.getPosition());
	float radiusSum = stake.getShape(3).getRadius() + ball.getRadius();



	return distance <= radiusSum * radiusSum;
}



float Collision::distanceSquared(sf::Vector2f a, sf::Vector2f b) //funkcja kwadratowa
{
	float distX = a.x - b.x; //odejmowanie wektorow x
	float distY = a.y - b.y;

	return distX * distX + distY * distY; //zwracanie dystansu
}

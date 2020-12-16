#include "Game.h"

void Game::initVariables()
{
	
	this->win->setFramerateLimit(60);
	this->tex.loadFromFile("Sprite/map.png");
	this->spr.setTexture(this->tex);

}

void Game::updateBallCollision(float& deltatime)
{
	//gPoint

		//__GPOINT for RED
		float distanceGPOINT = collision.distanceSquared(player.getPosition(), gPoint.getPosition());
		float distanceSquaredGPOINT = sqrtf(distanceGPOINT);
		float overlapGPOINT = (distanceSquaredGPOINT - gPoint.getRadius() - player.getRadius()) / 2.f;

		float moveXGPOINT = (overlapGPOINT * (gPoint.getPosition().x - player.getPosition().x) / distanceSquaredGPOINT);
		float moveYGPOINT = (overlapGPOINT * (gPoint.getPosition().y - player.getPosition().y) / distanceSquaredGPOINT);

		//gPoint setPos Red
		gPoint.setPosition((ball.getPosition().x - moveXGPOINT) + 15.f, (ball.getPosition().y - moveYGPOINT) + 15.f);
	

		if (this->addBluePlayer == true)
		{
			//__GPOINT for BLUE
			float distanceGPOINTBLUE = collision.distanceSquared(playerBlue.getPosition(), gPointBlue.getPosition());
			float distanceSquaredGPOINTBLUE = sqrtf(distanceGPOINTBLUE);
			float overlapGPOINTBLUE = (distanceSquaredGPOINTBLUE - gPointBlue.getRadius() - playerBlue.getRadius()) / 2.f;

			float moveXGPOINTBLUE = (overlapGPOINTBLUE * (gPointBlue.getPosition().x - playerBlue.getPosition().x) / distanceSquaredGPOINTBLUE);
			float moveYGPOINTBLUE = (overlapGPOINTBLUE * (gPointBlue.getPosition().y - playerBlue.getPosition().y) / distanceSquaredGPOINTBLUE);

			//gPoint setPos Blue
			gPointBlue.setPosition((ball.getPosition().x - moveXGPOINTBLUE) + 15.f, (ball.getPosition().y - moveYGPOINTBLUE) + 15.f);
		}
		/////////////////////////////////////////////////////////////////

		//Red Player
		if (collision.ballOverPlayer(ball, player)) //jesli sie zderza
		{
			float distance = collision.distanceSquared(ball.getPosition(), player.getPosition()); //dystans pomiedzy srodkami dwoch kul
			float distanceSquared = sqrtf(distance); //musimy zrobic pierwiastek z pitagorejczyka
			float overlap = (distanceSquared - ball.getRadius() - player.getRadius()) / 2.f; //nakladanie sie

			float moveX = (overlap * (ball.getPosition().x - player.getPosition().x) / distanceSquared);
			float moveY = (overlap * (ball.getPosition().y - player.getPosition().y) / distanceSquared);

			ball.setPosition(ball.getPosition().x - moveX, ball.getPosition().y - moveY);
			player.setPosition(player.getPosition().x + moveX, player.getPosition().y + moveY);

			//wektory po zderzeniu
			sf::Vector2f normal((player.getPosition().x - ball.getPosition().x) / distanceSquared, (player.getPosition().y - ball.getPosition().y) / distanceSquared);
			sf::Vector2f tangent(-normal.y, normal.x);

			//predkosci do stycznej
			float dotProductTangent1 = ball.getVelocity().x * tangent.x + ball.getVelocity().y * tangent.y;
			float dotProductTangent2 = player.getVelocity().x * tangent.x + player.getVelocity().y * tangent.y;

			//predkosci do normalnej
			float dotProductNormal1 = ball.getVelocity().x * normal.x + ball.getVelocity().y * normal.y;
			float dotProductNormal2 = player.getVelocity().x * normal.x + player.getVelocity().y * normal.y;

			//koncowe predkosci z zasady pêdu

			float m1 = (dotProductNormal1 * (ball.getMass() - player.getMass()) + 2.95f * ball.getMass() * dotProductNormal2) / (ball.getMass() + player.getMass());
			float m2 = (dotProductNormal2 * (player.getMass() - ball.getMass()) + 2.95f * ball.getMass() * dotProductNormal1) / (ball.getMass() + player.getMass());

			dt = clock.restart().asSeconds();

			//nadajemy predkosci
			ball.setVelocity(tangent.x * dotProductTangent1 + normal.x * m1, tangent.y * dotProductTangent1 + normal.y * m1);
			player.setVelocity(tangent.x * dotProductTangent2 + normal.x * m2, tangent.y * dotProductTangent2 + normal.y * m2);
		}
		else
		{

			ball.setAcceleration(-ball.getVelocity().x * 20000.f * deltatime, -ball.getVelocity().y * 20000.f * deltatime); //Zwolnienie
			ball.setVelocity(ball.getVelocity().x + (ball.getAcceleration().x), ball.getVelocity().y + (ball.getAcceleration().y));

			player.setAcceleration(-player.getVelocity().x * 20000.f * deltatime, -player.getVelocity().y * 20000.f * deltatime); //Zwolnienie
			player.setVelocity(player.getVelocity().x + (player.getAcceleration().x), player.getVelocity().y + (player.getAcceleration().y));
		}

		//Blue Player
		
		if (this->addBluePlayer == true)
		{
			if (collision.ballOverPlayerBLUE(ball, playerBlue)) //jesli sie zderza
			{

				float distanceBLUE = collision.distanceSquared(ball.getPosition(), playerBlue.getPosition()); //dystans pomiedzy srodkami dwoch kul
				float distanceSquaredBLUE = sqrtf(distanceBLUE); //musimy zrobic pierwiastek z pitagorejczyka
				float overlapBLUE = (distanceSquaredBLUE - ball.getRadius() - playerBlue.getRadius()) / 2.f; //nakladanie sie

				float moveXBLUE = (overlapBLUE * (ball.getPosition().x - playerBlue.getPosition().x) / distanceSquaredBLUE);
				float moveYBLUE = (overlapBLUE * (ball.getPosition().y - playerBlue.getPosition().y) / distanceSquaredBLUE);

				ball.setPosition(ball.getPosition().x - moveXBLUE, ball.getPosition().y - moveYBLUE);
				playerBlue.setPosition(playerBlue.getPosition().x + moveXBLUE, playerBlue.getPosition().y + moveYBLUE);


				//wektory po zderzeniu
				sf::Vector2f normalBLUE((playerBlue.getPosition().x - ball.getPosition().x) / distanceSquaredBLUE, (playerBlue.getPosition().y - ball.getPosition().y) / distanceSquaredBLUE);
				sf::Vector2f tangentBLUE(-normalBLUE.y, normalBLUE.x);

				//predkosci do stycznej
				float dotProductTangent1BLUE = ball.getVelocity().x * tangentBLUE.x + ball.getVelocity().y * tangentBLUE.y;
				float dotProductTangent2BLUE = playerBlue.getVelocity().x * tangentBLUE.x + playerBlue.getVelocity().y * tangentBLUE.y;

				//predkosci do normalnej
				float dotProductNormal1BLUE = ball.getVelocity().x * normalBLUE.x + ball.getVelocity().y * normalBLUE.y;
				float dotProductNormal2BLUE = playerBlue.getVelocity().x * normalBLUE.x + playerBlue.getVelocity().y * normalBLUE.y;

				//koncowe predkosci z zasady pêdu

				float m1BLUE = (dotProductNormal1BLUE * (ball.getMass() - playerBlue.getMass()) + 2.95f * ball.getMass() * dotProductNormal2BLUE) / (ball.getMass() + playerBlue.getMass());
				float m2BLUE = (dotProductNormal2BLUE * (playerBlue.getMass() - ball.getMass()) + 2.95f * ball.getMass() * dotProductNormal1BLUE) / (ball.getMass() + playerBlue.getMass());

				dt = clock.restart().asSeconds();

				//nadajemy predkosci
				ball.setVelocity(tangentBLUE.x * dotProductTangent1BLUE + normalBLUE.x * m1BLUE, tangentBLUE.y * dotProductTangent1BLUE + normalBLUE.y * m1BLUE);
				playerBlue.setVelocity(tangentBLUE.x * dotProductTangent2BLUE + normalBLUE.x * m2BLUE, tangentBLUE.y * dotProductTangent2BLUE + normalBLUE.y * m2BLUE);
			}
			else
			{

				
				playerBlue.setAcceleration(-playerBlue.getVelocity().x * 20000.f * deltatime, -playerBlue.getVelocity().y * 20000.f * deltatime); //Zwolnienie
				playerBlue.setVelocity(playerBlue.getVelocity().x + (playerBlue.getAcceleration().x), playerBlue.getVelocity().y + (playerBlue.getAcceleration().y));
			}
			
		}
		
		
	}
	


void Game::updatePlayerCollision(float& deltatime)
{
	if (this->addBluePlayer == true)
	{
		if (collision.playerOverPlayer(player, playerBlue)) //jesli sie zderza
		{

			float distancePLAYER = collision.distanceSquared(player.getPosition(), playerBlue.getPosition()); //dystans pomiedzy srodkami dwoch kul
			float distanceSquaredPLAYER = sqrtf(distancePLAYER); //musimy zrobic pierwiastek z pitagorejczyka
			float overlapPLAYER = (distanceSquaredPLAYER - player.getRadius() - playerBlue.getRadius()) / 2.f; //nakladanie sie

			float moveXPLAYER = (overlapPLAYER * (player.getPosition().x - playerBlue.getPosition().x) / distanceSquaredPLAYER);
			float moveYPLAYER = (overlapPLAYER * (player.getPosition().y - playerBlue.getPosition().y) / distanceSquaredPLAYER);

			player.setPosition(player.getPosition().x - moveXPLAYER, player.getPosition().y - moveYPLAYER);
			playerBlue.setPosition(playerBlue.getPosition().x + moveXPLAYER, playerBlue.getPosition().y + moveYPLAYER);


			//wektory po zderzeniu
			sf::Vector2f normalPLAYER((playerBlue.getPosition().x - player.getPosition().x) / distanceSquaredPLAYER, (playerBlue.getPosition().y - player.getPosition().y) / distanceSquaredPLAYER);
			sf::Vector2f tangentPLAYER(-normalPLAYER.y, normalPLAYER.x);

			//predkosci do stycznej
			float dotProductTangent1PLAYER = player.getVelocity().x * tangentPLAYER.x + player.getVelocity().y * tangentPLAYER.y;
			float dotProductTangent2PLAYER = playerBlue.getVelocity().x * tangentPLAYER.x + playerBlue.getVelocity().y * tangentPLAYER.y;

			//predkosci do normalnej
			float dotProductNormal1PLAYER = player.getVelocity().x * normalPLAYER.x + player.getVelocity().y * normalPLAYER.y;
			float dotProductNormal2PLAYER = playerBlue.getVelocity().x * normalPLAYER.x + playerBlue.getVelocity().y * normalPLAYER.y;

			//koncowe predkosci z zasady pêdu

			float m1PLAYER = (dotProductNormal1PLAYER * (player.getMass() - playerBlue.getMass()) + 2.95f * player.getMass() * dotProductNormal2PLAYER) / (player.getMass() + playerBlue.getMass());
			float m2PLAYER = (dotProductNormal2PLAYER * (playerBlue.getMass() - player.getMass()) + 2.95f * player.getMass() * dotProductNormal1PLAYER) / (player.getMass() + playerBlue.getMass());

			dt = clock.restart().asSeconds();

			//nadajemy predkosci
			player.setVelocity(tangentPLAYER.x * dotProductTangent1PLAYER + normalPLAYER.x * m1PLAYER, tangentPLAYER.y * dotProductTangent1PLAYER + normalPLAYER.y * m1PLAYER);
			playerBlue.setVelocity(tangentPLAYER.x * dotProductTangent2PLAYER + normalPLAYER.x * m2PLAYER, tangentPLAYER.y * dotProductTangent2PLAYER + normalPLAYER.y * m2PLAYER);
		}
		else
		{
			player.setAcceleration(-player.getVelocity().x * 20000.f * deltatime, -player.getVelocity().y * 20000.f * deltatime); //Zwolnienie
			player.setVelocity(player.getVelocity().x + (player.getAcceleration().x), player.getVelocity().y + (player.getAcceleration().y));

			playerBlue.setAcceleration(-playerBlue.getVelocity().x * 20000.f * deltatime, -playerBlue.getVelocity().y * 20000.f * deltatime); //Zwolnienie
			playerBlue.setVelocity(playerBlue.getVelocity().x + (playerBlue.getAcceleration().x), playerBlue.getVelocity().y + (playerBlue.getAcceleration().y));
		}
	}
}

void Game::updateStakeCollision()
{
	//For PlayerRed
	// LEFT UP STAKE
	if (collision.l_UpStakeOverPlayer(stake, player))
	{

		float distance = collision.distanceSquared(stake.getShape(0).getPosition(), player.getPosition());
		float distanceSquared = sqrt(distance);
		float overlap = (distanceSquared - stake.getShape(0).getRadius() - player.getRadius()) / 2.f;

		float moveX = (overlap * (stake.getShape(0).getPosition().x - player.getPosition().x) / distanceSquared);
		float moveY = (overlap * (stake.getShape(0).getPosition().y - player.getPosition().y) / distanceSquared);

		player.setPosition(player.getPosition().x + moveX, player.getPosition().y + moveY);


	}

	//LEFT DOWN STAKE

	if (collision.l_DownStakeOverPlayer(stake, player))
	{

		float distance = collision.distanceSquared(stake.getShape(1).getPosition(), player.getPosition());
		float distanceSquared = sqrt(distance);
		float overlap = (distanceSquared - stake.getShape(1).getRadius() - player.getRadius()) / 2.f;

		float moveX = (overlap * (stake.getShape(1).getPosition().x - player.getPosition().x) / distanceSquared);
		float moveY = (overlap * (stake.getShape(1).getPosition().y - player.getPosition().y) / distanceSquared);

		player.setPosition(player.getPosition().x + moveX, player.getPosition().y + moveY);


	}

	//RIGHT UP STAKE

	if (collision.r_UpStakeOverPlayer(stake, player))
	{

		float distance = collision.distanceSquared(stake.getShape(2).getPosition(), player.getPosition());
		float distanceSquared = sqrt(distance);
		float overlap = (distanceSquared - stake.getShape(2).getRadius() - player.getRadius()) / 2.f;

		float moveX = (overlap * (stake.getShape(2).getPosition().x - player.getPosition().x) / distanceSquared);
		float moveY = (overlap * (stake.getShape(2).getPosition().y - player.getPosition().y) / distanceSquared);

		player.setPosition(player.getPosition().x + moveX, player.getPosition().y + moveY);


	}

	//RIGHT DOWN STAKE

	if (collision.r_DownStakeOverPlayer(stake, player))
	{

		float distance = collision.distanceSquared(stake.getShape(3).getPosition(), player.getPosition());
		float distanceSquared = sqrt(distance);
		float overlap = (distanceSquared - stake.getShape(3).getRadius() - player.getRadius()) / 2.f;

		float moveX = (overlap * (stake.getShape(3).getPosition().x - player.getPosition().x) / distanceSquared);
		float moveY = (overlap * (stake.getShape(3).getPosition().y - player.getPosition().y) / distanceSquared);

		player.setPosition(player.getPosition().x + moveX, player.getPosition().y + moveY);


	}

	//////////////////////////////////////////For Ball and Stakes

	// LEFT UP STAKE
	if (collision.l_UpStakeOverBall(stake, ball))
	{

		float distance = collision.distanceSquared(stake.getShape(0).getPosition(), ball.getPosition());
		float distanceSquared = sqrt(distance);
		float overlap = (distanceSquared - stake.getShape(0).getRadius() - ball.getRadius()) / 2.f;

		float moveX = (overlap * (stake.getShape(0).getPosition().x - ball.getPosition().x) / distanceSquared);
		float moveY = (overlap * (stake.getShape(0).getPosition().y - ball.getPosition().y) / distanceSquared);

		ball.setPosition(ball.getPosition().x + moveX, ball.getPosition().y + moveY);

		//wektory po zderzeniu
		sf::Vector2f normal((ball.getPosition().x - stake.getShape(0).getPosition().x) / distanceSquared, (ball.getPosition().y - stake.getShape(0).getPosition().y) / distanceSquared);
		sf::Vector2f tangent(-normal.y, normal.x);

		//predkosci do stycznej
		float dotProductTangent1 = ball.getVelocity().x * tangent.x + ball.getVelocity().y * tangent.y;

		//predkosci do normalnej
		float dotProductNormal1 = ball.getVelocity().x * normal.x + ball.getVelocity().y * normal.y;
		float dotProductNormal2 = stake.getVelocity().x * normal.x + stake.getVelocity().y * normal.y;

		//koncowe predkosci z zasady pêdu

		float m1 = (dotProductNormal1 * (ball.getMass() - stake.getMass()) + 2.95f * ball.getMass() * dotProductNormal2) / (ball.getMass() + player.getMass());
	
		//nadajemy predkosci
		ball.setVelocity(tangent.x * dotProductTangent1 + normal.x * m1, tangent.y * dotProductTangent1 + normal.y * m1);

	}

	//LEFT DOWN STAKE

	if (collision.l_DownStakeOverBall(stake, ball))
	{

		float distance = collision.distanceSquared(stake.getShape(1).getPosition(), ball.getPosition());
		float distanceSquared = sqrt(distance);
		float overlap = (distanceSquared - stake.getShape(1).getRadius() - ball.getRadius()) / 2.f;

		float moveX = (overlap * (stake.getShape(1).getPosition().x - ball.getPosition().x) / distanceSquared);
		float moveY = (overlap * (stake.getShape(1).getPosition().y - ball.getPosition().y) / distanceSquared);

		ball.setPosition(ball.getPosition().x + moveX, ball.getPosition().y + moveY);

		//wektory po zderzeniu
		sf::Vector2f normal((ball.getPosition().x - stake.getShape(1).getPosition().x) / distanceSquared, (ball.getPosition().y - stake.getShape(1).getPosition().y) / distanceSquared);
		sf::Vector2f tangent(-normal.y, normal.x);

		//predkosci do stycznej
		float dotProductTangent1 = ball.getVelocity().x * tangent.x + ball.getVelocity().y * tangent.y;

		//predkosci do normalnej
		float dotProductNormal1 = ball.getVelocity().x * normal.x + ball.getVelocity().y * normal.y;
		float dotProductNormal2 = stake.getVelocity().x * normal.x + stake.getVelocity().y * normal.y;

		//koncowe predkosci z zasady pêdu

		float m1 = (dotProductNormal1 * (ball.getMass() - stake.getMass()) + 2.95f * ball.getMass() * dotProductNormal2) / (ball.getMass() + player.getMass());

		//nadajemy predkosci
		ball.setVelocity(tangent.x * dotProductTangent1 + normal.x * m1, tangent.y * dotProductTangent1 + normal.y * m1);

	}

	//RIGHT UP STAKE

	if (collision.r_UpStakeOverBall(stake, ball))
	{

		float distance = collision.distanceSquared(stake.getShape(2).getPosition(), ball.getPosition());
		float distanceSquared = sqrt(distance);
		float overlap = (distanceSquared - stake.getShape(2).getRadius() - ball.getRadius()) / 2.f;

		float moveX = (overlap * (stake.getShape(2).getPosition().x - ball.getPosition().x) / distanceSquared);
		float moveY = (overlap * (stake.getShape(2).getPosition().y - ball.getPosition().y) / distanceSquared);

		ball.setPosition(ball.getPosition().x + moveX, ball.getPosition().y + moveY);

		//wektory po zderzeniu
		sf::Vector2f normal((ball.getPosition().x - stake.getShape(2).getPosition().x) / distanceSquared, (ball.getPosition().y - stake.getShape(2).getPosition().y) / distanceSquared);
		sf::Vector2f tangent(-normal.y, normal.x);

		//predkosci do stycznej
		float dotProductTangent1 = ball.getVelocity().x * tangent.x + ball.getVelocity().y * tangent.y;

		//predkosci do normalnej
		float dotProductNormal1 = ball.getVelocity().x * normal.x + ball.getVelocity().y * normal.y;
		float dotProductNormal2 = stake.getVelocity().x * normal.x + stake.getVelocity().y * normal.y;

		//koncowe predkosci z zasady pêdu

		float m1 = (dotProductNormal1 * (ball.getMass() - stake.getMass()) + 2.95f * ball.getMass() * dotProductNormal2) / (ball.getMass() + player.getMass());

		//nadajemy predkosci
		ball.setVelocity(tangent.x* dotProductTangent1 + normal.x * m1, tangent.y* dotProductTangent1 + normal.y * m1);


		
	}

	//RIGHT DOWN STAKE

	if (collision.r_DownStakeOverBall(stake, ball))
	{

		float distance = collision.distanceSquared(stake.getShape(3).getPosition(), ball.getPosition());
		float distanceSquared = sqrt(distance);
		float overlap = (distanceSquared - stake.getShape(3).getRadius() - ball.getRadius()) / 2.f;

		float moveX = (overlap * (stake.getShape(3).getPosition().x - ball.getPosition().x) / distanceSquared);
		float moveY = (overlap * (stake.getShape(3).getPosition().y - ball.getPosition().y) / distanceSquared);

		ball.setPosition(ball.getPosition().x + moveX, ball.getPosition().y + moveY);

		//wektory po zderzeniu
		sf::Vector2f normal((ball.getPosition().x - stake.getShape(3).getPosition().x) / distanceSquared, (ball.getPosition().y - stake.getShape(3).getPosition().y) / distanceSquared);
		sf::Vector2f tangent(-normal.y, normal.x);

		//predkosci do stycznej
		float dotProductTangent1 = ball.getVelocity().x * tangent.x + ball.getVelocity().y * tangent.y;

		//predkosci do normalnej
		float dotProductNormal1 = ball.getVelocity().x * normal.x + ball.getVelocity().y * normal.y;
		float dotProductNormal2 = stake.getVelocity().x * normal.x + stake.getVelocity().y * normal.y;

		//koncowe predkosci z zasady pêdu

		float m1 = (dotProductNormal1 * (ball.getMass() - stake.getMass()) + 2.95f * ball.getMass() * dotProductNormal2) / (ball.getMass() + player.getMass());

		//nadajemy predkosci
		ball.setVelocity(tangent.x* dotProductTangent1 + normal.x * m1, tangent.y* dotProductTangent1 + normal.y * m1);

	}


	//Player Blue
	// LEFT UP STAKE
	if (collision.l_UpStakeOverPlayerBlue(stake, playerBlue))
	{

		float distance = collision.distanceSquared(stake.getShape(0).getPosition(), playerBlue.getPosition());
		float distanceSquared = sqrt(distance);
		float overlap = (distanceSquared - stake.getShape(0).getRadius() - playerBlue.getRadius()) / 2.f;

		float moveX = (overlap * (stake.getShape(0).getPosition().x - playerBlue.getPosition().x) / distanceSquared);
		float moveY = (overlap * (stake.getShape(0).getPosition().y - playerBlue.getPosition().y) / distanceSquared);

		playerBlue.setPosition(playerBlue.getPosition().x + moveX, playerBlue.getPosition().y + moveY);


	}

	//LEFT DOWN STAKE

	if (collision.l_DownStakeOverPlayerBlue(stake, playerBlue))
	{

		float distance = collision.distanceSquared(stake.getShape(1).getPosition(), playerBlue.getPosition());
		float distanceSquared = sqrt(distance);
		float overlap = (distanceSquared - stake.getShape(1).getRadius() - playerBlue.getRadius()) / 2.f;

		float moveX = (overlap * (stake.getShape(1).getPosition().x - playerBlue.getPosition().x) / distanceSquared);
		float moveY = (overlap * (stake.getShape(1).getPosition().y - playerBlue.getPosition().y) / distanceSquared);

		playerBlue.setPosition(playerBlue.getPosition().x + moveX, playerBlue.getPosition().y + moveY);


	}

	//RIGHT UP STAKE

	if (collision.r_UpStakeOverPlayerBlue(stake, playerBlue))
	{

		float distance = collision.distanceSquared(stake.getShape(2).getPosition(), playerBlue.getPosition());
		float distanceSquared = sqrt(distance);
		float overlap = (distanceSquared - stake.getShape(2).getRadius() - playerBlue.getRadius()) / 2.f;

		float moveX = (overlap * (stake.getShape(2).getPosition().x - playerBlue.getPosition().x) / distanceSquared);
		float moveY = (overlap * (stake.getShape(2).getPosition().y - playerBlue.getPosition().y) / distanceSquared);

		playerBlue.setPosition(playerBlue.getPosition().x + moveX, playerBlue.getPosition().y + moveY);


	}

	//RIGHT DOWN STAKE

	if (collision.r_DownStakeOverPlayerBlue(stake, playerBlue))
	{

		float distance = collision.distanceSquared(stake.getShape(3).getPosition(), playerBlue.getPosition());
		float distanceSquared = sqrt(distance);
		float overlap = (distanceSquared - stake.getShape(3).getRadius() - playerBlue.getRadius()) / 2.f;

		float moveX = (overlap * (stake.getShape(3).getPosition().x - playerBlue.getPosition().x) / distanceSquared);
		float moveY = (overlap * (stake.getShape(3).getPosition().y - playerBlue.getPosition().y) / distanceSquared);

		playerBlue.setPosition(playerBlue.getPosition().x + moveX, playerBlue.getPosition().y + moveY);


	}

	

}

void Game::updateGui()
{
	//updateGui
	if (!this->font.loadFromFile("Font/ariblk.ttf"))
		std::cout << "Couldn't Load the Font!" << "\n";

	std::stringstream ss;

	std::string title = "Red Scored!";

    dt = clock.getElapsedTime().asSeconds();

	if (this->ball.getRightSideBall() >= this->goal.getLeftSideGoal_RIGHT())
	{

		this->pointRed += 1;
		this->redtitle.titleSet(sf::Color::Red, title);

		this->ball.setPosition(463.f, 215.f);
		this->player.setPosition(150.f, 208.f);
		this->playerBlue.setPosition(770.f, 208.f);

		this->ball.setVelocity(0.f, 0.f);
		this->player.setVelocity(0.f, 0.f);
		this->playerBlue.setVelocity(0.f, 0.f);

	}

	else if (dt >= 2.f)
	{
		title = "";
		this->redtitle.titleSet(sf::Color::Red, title);
	}

	if (this->ball.getLeftSideBall() <= this->goal.getRightSideGoal_LEFT())
	{
		this->pointBlue += 1;
		title = "Blue Scored!";
		this->bluetitle.titleSet(sf::Color::Blue, title);

		this->ball.setPosition(463.f, 215.f);
		this->player.setPosition(150.f, 208.f);
		this->playerBlue.setPosition(770.f, 208.f);

		this->ball.setVelocity(0.f, 0.f);
		this->player.setVelocity(0.f, 0.f);
		this->playerBlue.setVelocity(0.f, 0.f);

	}

	else if (dt >= 2.f)
	{
		title = "";
		this->bluetitle.titleSet(sf::Color::Blue, title);
	}

	
	//std::cout << dt << "\n";


	this->czasMilisekundy = clockGameTime.getElapsedTime().asSeconds();
	if (this->czasMilisekundy >= 9.47f)
	{
		this->czasMilisekundy = clockGameTime.restart().asSeconds();

			this->czasMilisekundy = clockGameTime.restart().asSeconds();
			this->czasSekundy += 1;
		
	}

	
	if (this->czasSekundy >= 6.f)
	{
		this->czasMinuty += 1;

		this->czasSekundy = clockGameTime.restart().asSeconds();
		this->czasMilisekundy = clockGameTime.restart().asSeconds();
	}
	

	ss << pointRed << " - " << pointBlue << "                                 " << "0" << static_cast<int>(round(czasMinuty))
		<< ":" << static_cast<int>(round(czasSekundy)) << static_cast<int>(round(czasMilisekundy));

	//restart
	if (this->pointRed == 3 || this->pointBlue == 3)
		this->restartGame();

	this->text.setFont(font);
	this->text.setCharacterSize(19);
	this->text.setFillColor(sf::Color::White);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setPosition(sf::Vector2f(327.f, 2.f));
	this->text.setString(ss.str());
}

void Game::restartGame()
{
	//Restart POS PLAYERS
	this->player.setPosition(150.f, 208.f);
	this->playerBlue.setPosition(770.f, 208.f);

	clock.restart();
	clockGameTime.restart();

	//RESTART POINTS AND TIMER
	this->czasMinuty = 0;
	this->czasSekundy = 0;
	this->czasMilisekundy = 0;
	this->czasMicrosekundy = 0;

	this->pointRed = 0;
	this->pointBlue = 0;

}

Game::Game()
{
	this->win = new sf::RenderWindow(sf::VideoMode(this->W, this->H), "...", sf::Style::Default);
	

	std::cout << "If you want play LAN, press 'I'" << "\n";
	std::cout << "If you want play Online, press 'O'" << "\n";
	std::cout << "If you want play 1v1 in computer, press 'P'" << "\n";

}

Game::~Game()
{
	delete this->win;
	//delete this->connect;
}

bool Game::isRunning() const
{
	this->win->isOpen();
	return true;

	return false;
}


void Game::update()
{
	this->initVariables();

	float deltatime = 0.f;
	sf::Clock clock;



	if (isRunning())
	{
		deltatime = clock.restart().asSeconds();


		sf::Event e;

		while (this->win->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				this->win->close();
		

		}


	
		updateBallCollision(deltatime);
		updatePlayerCollision(deltatime);
		updateStakeCollision();
		updateGui();

		ball.update(deltatime, *this->win, *this->win, ball, player, playerBlue, gPoint, gPointBlue);
		player.updateRed(deltatime, this->win);

		if (addBluePlayer == true) { playerBlue.updateBlue(deltatime, this->win); }

		//LAN
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
		{
			this->connect = new Connect(&ip_LAN, PORT);
			this->addBluePlayer = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		{
			this->connect = new Connect(&ip_PUBLIC, PORT);
			this->addBluePlayer = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			this->addBluePlayer = true;

		}
		

		//gPoint update
		gPoint.update(deltatime, this->win);
		gPointBlue.update(deltatime, this->win);

		redtitle.update(deltatime);
		bluetitle.update(deltatime);


	}

}


void Game::render()
{

	//WIN CLEAR

	this->win->clear();


		this->win->draw(this->spr);
		player.draw(this->win);

		if (addBluePlayer == true) { playerBlue.draw(this->win); }
		

		ball.draw(*this->win);
		gPoint.draw(this->win);
		gPointBlue.draw(this->win);
		map.render(*this->win);
		stake.render(*this->win);
		goal.render(*this->win);
		scorebar.render(*this->win);

		//TEXT RENDER
		this->redtitle.render(*this->win);
		this->bluetitle.render(*this->win);
		this->win->draw(this->text);
	
	
	//WIN DISPLAY
	this->win->display();

	
}



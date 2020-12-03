#include "Game.h"

void Game::initVariables()
{
	

	this->win->setFramerateLimit(60);
	this->tex.loadFromFile("Sprite/map.png");
	this->spr.setTexture(this->tex);	

	this->onkeyHold = false;


	if (!deleteMenuSprites)
	{
		//Menu
		this->texture[0].loadFromFile("Sprite/menu.png");
		this->MenuSprite.setTexture(texture[0]);

		//Button
		
		this->texture[1].setSmooth(true);
		this->button.setPosition(sf::Vector2f(365.f, 300.f));
		

		//String
		this->fontArial.loadFromFile("Font/arial.ttf");
		this->textFont.setFont(fontArial);

		this->textFont.setFillColor(sf::Color::White);
		this->textFont.setPosition(sf::Vector2f(325.f, 250.f));
		this->textFont.setCharacterSize(25);
		this->textFont.setString(this->player_input);
	}

}

void Game::updateBallCollision(float& deltatime)
{

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
		}

		//Blue Player
		if (collision.ballOverPlayer(ball, playerBlue)) //jesli sie zderza
		{

			float distance = collision.distanceSquared(ball.getPosition(), playerBlue.getPosition()); //dystans pomiedzy srodkami dwoch kul
			float distanceSquared = sqrtf(distance); //musimy zrobic pierwiastek z pitagorejczyka
			float overlap = (distanceSquared - ball.getRadius() - playerBlue.getRadius()) / 2.f; //nakladanie sie

			float moveX = (overlap * (ball.getPosition().x - playerBlue.getPosition().x) / distanceSquared);
			float moveY = (overlap * (ball.getPosition().y - playerBlue.getPosition().y) / distanceSquared);

			ball.setPosition(ball.getPosition().x - moveX, ball.getPosition().y - moveY);
			playerBlue.setPosition(playerBlue.getPosition().x + moveX, playerBlue.getPosition().y + moveY);


			//wektory po zderzeniu
			sf::Vector2f normal((playerBlue.getPosition().x - ball.getPosition().x) / distanceSquared, (playerBlue.getPosition().y - ball.getPosition().y) / distanceSquared);
			sf::Vector2f tangent(-normal.y, normal.x);

			//predkosci do stycznej
			float dotProductTangent1 = ball.getVelocity().x * tangent.x + ball.getVelocity().y * tangent.y;
			float dotProductTangent2 = playerBlue.getVelocity().x * tangent.x + playerBlue.getVelocity().y * tangent.y;

			//predkosci do normalnej
			float dotProductNormal1 = ball.getVelocity().x * normal.x + ball.getVelocity().y * normal.y;
			float dotProductNormal2 = playerBlue.getVelocity().x * normal.x + playerBlue.getVelocity().y * normal.y;

			//koncowe predkosci z zasady pêdu

			float m1 = (dotProductNormal1 * (ball.getMass() - playerBlue.getMass()) + 2.95f * ball.getMass() * dotProductNormal2) / (ball.getMass() + playerBlue.getMass());
			float m2 = (dotProductNormal2 * (playerBlue.getMass() - ball.getMass()) + 2.95f * ball.getMass() * dotProductNormal1) / (ball.getMass() + playerBlue.getMass());

			dt = clock.restart().asSeconds();

			//nadajemy predkosci
			ball.setVelocity(tangent.x * dotProductTangent1 + normal.x * m1, tangent.y * dotProductTangent1 + normal.y * m1);
			playerBlue.setVelocity(tangent.x * dotProductTangent2 + normal.x * m2, tangent.y * dotProductTangent2 + normal.y * m2);
		}
		else
		{

			ball.setAcceleration(-ball.getVelocity().x * 20000.f * deltatime, -ball.getVelocity().y * 20000.f * deltatime); //Zwolnienie
			ball.setVelocity(ball.getVelocity().x + (ball.getAcceleration().x), ball.getVelocity().y + (ball.getAcceleration().y));
		}
	}



void Game::updatePlayerCollision(float& deltatime)
{
	if (collision.playerOverPlayer(player, playerBlue)) //jesli sie zderza
	{

		float distance = collision.distanceSquared(player.getPosition(), playerBlue.getPosition()); //dystans pomiedzy srodkami dwoch kul
		float distanceSquared = sqrtf(distance); //musimy zrobic pierwiastek z pitagorejczyka
		float overlap = (distanceSquared - player.getRadius() - playerBlue.getRadius()) / 2.f; //nakladanie sie

		float moveX = (overlap * (player.getPosition().x - playerBlue.getPosition().x) / distanceSquared);
		float moveY = (overlap * (player.getPosition().y - playerBlue.getPosition().y) / distanceSquared);

		player.setPosition(player.getPosition().x - moveX, player.getPosition().y - moveY);
		playerBlue.setPosition(playerBlue.getPosition().x + moveX, playerBlue.getPosition().y + moveY);


		//wektory po zderzeniu
		sf::Vector2f normal((playerBlue.getPosition().x - player.getPosition().x) / distanceSquared, (playerBlue.getPosition().y - player.getPosition().y) / distanceSquared);
		sf::Vector2f tangent(-normal.y, normal.x);

		//predkosci do stycznej
		float dotProductTangent1 = player.getVelocity().x * tangent.x + player.getVelocity().y * tangent.y;
		float dotProductTangent2 = playerBlue.getVelocity().x * tangent.x + playerBlue.getVelocity().y * tangent.y;

		//predkosci do normalnej
		float dotProductNormal1 = player.getVelocity().x * normal.x + player.getVelocity().y * normal.y;
		float dotProductNormal2 = playerBlue.getVelocity().x * normal.x + playerBlue.getVelocity().y * normal.y;

		//koncowe predkosci z zasady pêdu

		float m1 = (dotProductNormal1 * (player.getMass() - playerBlue.getMass()) + 2.95f * player.getMass() * dotProductNormal2) / (player.getMass() + playerBlue.getMass());
		float m2 = (dotProductNormal2 * (playerBlue.getMass() - player.getMass()) + 2.95f * player.getMass() * dotProductNormal1) / (player.getMass() + playerBlue.getMass());

		dt = clock.restart().asSeconds();

		//nadajemy predkosci
		player.setVelocity(tangent.x * dotProductTangent1 + normal.x * m1, tangent.y * dotProductTangent1 + normal.y * m1);
		playerBlue.setVelocity(tangent.x * dotProductTangent2 + normal.x * m2, tangent.y * dotProductTangent2 + normal.y * m2);
	}
	else
	{

		player.setAcceleration(-player.getVelocity().x * 20000.f * deltatime, -player.getVelocity().y * 20000.f * deltatime); //Zwolnienie
		player.setVelocity(player.getVelocity().x + (player.getAcceleration().x), player.getVelocity().y + (player.getAcceleration().y));
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


	this->text.setFont(font);
	this->text.setCharacterSize(19);
	this->text.setFillColor(sf::Color::White);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setPosition(sf::Vector2f(327.f, 2.f));
	this->text.setString(ss.str());
}

Game::Game()
{
	this->win = new sf::RenderWindow(sf::VideoMode(this->W, this->H), "...", sf::Style::Default);


}

Game::~Game()
{
	delete this->win;
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


		this->deleteGameSprites = true;
		this->deleteMenuSprites = false;

		sf::Event e;

		while (this->win->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				this->win->close();
		

			if (e.type == sf::Event::TextEntered) {
				if (e.text.unicode == '\b') { // handle backspace explicitly
					if (player_input.getSize() == 0)
					{
						player_input.erase(0, 0);

					}
					else {
						player_input.erase(player_input.getSize() - 1, 1);

					}

				}
				else { // all other keypresses
					player_input += static_cast<char>(e.text.unicode);

					if (player_input.getSize() >= 15)
					{
						player_input.erase(player_input.getSize() - 1, 1);
					}

				}
			}

		}

		if (player_input.getSize() == 0)
		{
			this->texture[1].loadFromFile("Sprite/locked_button.png");
			this->button.setTexture(texture[1]);
		}
		
		else if (player_input.getSize() > 0)
		{
		
			//Texture button
			this->texture[1].loadFromFile("Sprite/normal_button.png");
			this->button.setTexture(texture[1]);
				
			if (player_input.getSize() >= 9)
			{

				this->deleteMenuSprites = true;
				this->deleteGameSprites = false;

			}
		}
		
		

		


		updateBallCollision(deltatime);
		updatePlayerCollision(deltatime);
		updateStakeCollision();
		updateGui();

		ball.update(deltatime, *this->win, *this->win, ball, player);
		player.updateRed(deltatime, this->win);
		playerBlue.updateBlue(deltatime, this->win);


		redtitle.update(deltatime);
		bluetitle.update(deltatime);


	}

}





void Game::render()
{

	//WIN CLEAR

	this->win->clear();

	if (!deleteMenuSprites)
	{
		this->win->draw(this->MenuSprite);
		this->win->draw(this->textFont);
		this->win->draw(this->button);
	}

	if (!deleteGameSprites)
	{
		this->win->draw(this->spr);
		player.draw(this->win);
		playerBlue.draw(this->win);
		ball.draw(*this->win);
		map.render(*this->win);
		stake.render(*this->win);
		goal.render(*this->win);
		scorebar.render(*this->win);

		//TEXT RENDER
		this->redtitle.render(*this->win);
		this->bluetitle.render(*this->win);
		this->win->draw(this->text);
	}
	
	//WIN DISPLAY
	this->win->display();

	
}



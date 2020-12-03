#include "Player.h"
#include "hitBoxMap.h"
#include "Collision.h"



void Player::initVariables()
{
	this->radius = 15.f;
	this->mass = (radius * 20.f);
	
}

Player::Player(std::string nickname, sf::Color colorPlayer, float x, float y) : 
nickname(nickname), 
colorPlayer(colorPlayer),
x(x),
y(y)
{
	this->initVariables();

	this->shape.setFillColor(colorPlayer);
	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setOutlineThickness(2.f);
	this->shape.setRadius(radius);
	this->shape.setOrigin(radius, radius);
	this->shape.setPosition(sf::Vector2f(x, y));
}

Player::~Player()
{
}

void Player::updateRed(float deltatime, sf::RenderTarget* target)
{

	hitBoxMap map;
	Collision col;

	float m = (getMass() + 2.95f) / getMass();

	setAcceleration(-getVelocity().x * 0.9f * deltatime, -getVelocity().y * 0.9f * deltatime); //Zwolnienie
	setVelocity(getVelocity().x + (getAcceleration().x), getVelocity().y + (getAcceleration().y)); //predkosc


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

		velocity.y = -1.94f;

		if (this->shape.getGlobalBounds().intersects(map.getBox(1).getGlobalBounds()))
		{
			velocity.y = 0.f;
		}



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			
			velocity.x = 1.94f;

			if (this->shape.getGlobalBounds().intersects(map.getBox(2).getGlobalBounds()))
			{
				velocity.x = 0.f;
			}

			
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			velocity.x = -1.94f;

			if (this->shape.getGlobalBounds().intersects(map.getBox(0).getGlobalBounds()))
			{
				velocity.x = 0.f;
			}

			
			
		}
		
		else {
			velocity.x = 0.f;
		}
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		velocity.x = 1.94f;

		if (this->shape.getGlobalBounds().intersects(map.getBox(2).getGlobalBounds()))
		{
			velocity.x = 0.f;
		}
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			velocity.y = 1.94f;

			if (this->shape.getGlobalBounds().intersects(map.getBox(3).getGlobalBounds()))
			{
				velocity.y = 0.f;
			}
			
		}
		else velocity.y = 0.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		velocity.y = 1.94f;

		if (this->shape.getGlobalBounds().intersects(map.getBox(3).getGlobalBounds()))
		{
			velocity.y = 0.f;
		}
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			velocity.x = 1.94f;
			
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			velocity.x = -1.94f;

			if (this->shape.getGlobalBounds().intersects(map.getBox(0).getGlobalBounds()))
			{
				velocity.x = 0.f;
			}

			
			
			
		}

		else velocity.x = 0.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		velocity.x = -1.94f;


		if (this->shape.getGlobalBounds().intersects(map.getBox(0).getGlobalBounds()))
		{
			velocity.x = 0.f;
		}
			
		
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{


			velocity.y = 1.94f;

			if (this->shape.getGlobalBounds().intersects(map.getBox(3).getGlobalBounds()))
			{
				velocity.y = 0.f;
			}
			
		}
		else velocity.y = 0.f;
	}
	else { //Release Buttons
		setAcceleration(-getVelocity().x * 20000.f * deltatime, -getVelocity().y * 20000.f * deltatime); //zwolnienie

		//LEFT
		if (this->shape.getGlobalBounds().intersects(map.getBox(0).getGlobalBounds()))
		{
			velocity.x = 0.f;
		}

		//UP
		if (this->shape.getGlobalBounds().intersects(map.getBox(1).getGlobalBounds()))
		{
			velocity.y = 0.f;
		}

		//RIGHT
		if (this->shape.getGlobalBounds().intersects(map.getBox(2).getGlobalBounds()))
		{
			velocity.x = 0.f;
		}

		//DOWN
		if (this->shape.getGlobalBounds().intersects(map.getBox(3).getGlobalBounds()))
		{
			velocity.y = 0.f;
		}

	}

	

	//Styczna i normalna do prêdkoœci
	

	//setVelocity(getAcceleration().x + (getVelocity().x), getAcceleration().y + (getVelocity().y));

	setVelocity(getAcceleration().x + (getVelocity().x) * m, getAcceleration().y + (getVelocity().y) * m);

	velocity.x = Approach(vecVelocityGoal.x, velocity.x, deltatime);
	velocity.y = Approach(vecVelocityGoal.y, velocity.y, deltatime);


	
	
	shape.move(getVelocity());
	

}

void Player::updateBlue(float deltatime, sf::RenderTarget* target)
{

		hitBoxMap map;
		Collision col;

		float m = (getMass() + 2.95f) / getMass();

		setAcceleration(-getVelocity().x * 0.9f * deltatime, -getVelocity().y * 0.9f * deltatime); //Zwolnienie
		setVelocity(getVelocity().x + (getAcceleration().x), getVelocity().y + (getAcceleration().y)); //predkosc


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{

			velocity.y = -1.94f;

			if (this->shape.getGlobalBounds().intersects(map.getBox(1).getGlobalBounds()))
			{
				velocity.y = 0.f;
			}



			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{

				velocity.x = 1.94f;

				if (this->shape.getGlobalBounds().intersects(map.getBox(2).getGlobalBounds()))
				{
					velocity.x = 0.f;
				}


			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				velocity.x = -1.94f;

				if (this->shape.getGlobalBounds().intersects(map.getBox(0).getGlobalBounds()))
				{
					velocity.x = 0.f;
				}



			}

			else {
				velocity.x = 0.f;
			}

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			velocity.x = 1.94f;

			if (this->shape.getGlobalBounds().intersects(map.getBox(2).getGlobalBounds()))
			{
				velocity.x = 0.f;
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				velocity.y = 1.94f;

				if (this->shape.getGlobalBounds().intersects(map.getBox(3).getGlobalBounds()))
				{
					velocity.y = 0.f;
				}

			}
			else velocity.y = 0.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			velocity.y = 1.94f;

			if (this->shape.getGlobalBounds().intersects(map.getBox(3).getGlobalBounds()))
			{
				velocity.y = 0.f;
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				velocity.x = 1.94f;

			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				velocity.x = -1.94f;

				if (this->shape.getGlobalBounds().intersects(map.getBox(0).getGlobalBounds()))
				{
					velocity.x = 0.f;
				}




			}

			else velocity.x = 0.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			velocity.x = -1.94f;


			if (this->shape.getGlobalBounds().intersects(map.getBox(0).getGlobalBounds()))
			{
				velocity.x = 0.f;
			}




			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{


				velocity.y = 1.94f;

				if (this->shape.getGlobalBounds().intersects(map.getBox(3).getGlobalBounds()))
				{
					velocity.y = 0.f;
				}

			}
			else velocity.y = 0.f;
		}
		else { //Release Buttons
			setAcceleration(-getVelocity().x * 20000.f * deltatime, -getVelocity().y * 20000.f * deltatime); //zwolnienie

			//LEFT
			if (this->shape.getGlobalBounds().intersects(map.getBox(0).getGlobalBounds()))
			{
				velocity.x = 0.f;
			}

			//UP
			if (this->shape.getGlobalBounds().intersects(map.getBox(1).getGlobalBounds()))
			{
				velocity.y = 0.f;
			}

			//RIGHT
			if (this->shape.getGlobalBounds().intersects(map.getBox(2).getGlobalBounds()))
			{
				velocity.x = 0.f;
			}

			//DOWN
			if (this->shape.getGlobalBounds().intersects(map.getBox(3).getGlobalBounds()))
			{
				velocity.y = 0.f;
			}

		}



		//Styczna i normalna do prêdkoœci


		//setVelocity(getAcceleration().x + (getVelocity().x), getAcceleration().y + (getVelocity().y));

		setVelocity(getAcceleration().x + (getVelocity().x) * m, getAcceleration().y + (getVelocity().y) * m);

		velocity.x = Approach(vecVelocityGoal.x, velocity.x, deltatime);
		velocity.y = Approach(vecVelocityGoal.y, velocity.y, deltatime);




		shape.move(getVelocity());


	}



void Player::draw(sf::RenderWindow* window)
{
	window->draw(this->shape);
}

void Player::setAcceleration(float x, float y)
{
	this->acceleration = sf::Vector2f(x, y);
}

void Player::setVelocity(float x, float y)
{
	this->velocity = sf::Vector2f(x, y);
}

void Player::setVecVelocityGoal(float x, float y)
{
	this->vecVelocityGoal = sf::Vector2f(x, y);
}

void Player::setPosition(float x, float y)
{
	this->shape.setPosition(sf::Vector2f(x, y));
}

void Player::setOutlineColor(sf::Color color)
{
	this->shape.setOutlineColor(color);
}


//bool Player::kickBall() const
//{
//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
//	{
//		this->shape.setOutlineColor(sf::Color::White);
//
//
//		return true;
//	}
//	else
//	{
//		this->shape.setOutlineColor(sf::Color::Black);
//
//
//	}
//	return false;
//}


float Player::Approach(float flGoal, float flCurrent, float dt) //podejœcie
{
	float flDifference = flGoal - flCurrent; // roznica celu dojscia i obecnej pozycji.

	if (flDifference > dt)
		return flCurrent + dt;
	if (flDifference < -dt) //jesli dystans jest niewystarczaj¹cy do osi¹gniecia celu.
		return flCurrent - dt;

	return flGoal;


}

float Player::getMass() const
{
	return mass;
}

float Player::getRadius() const
{
	return radius;
}

sf::Vector2f Player::getOrigin() const
{
	return shape.getOrigin();
}

sf::Vector2f Player::getAcceleration() const
{
	return acceleration;
}

sf::Vector2f Player::getVelocity() const
{
	return velocity;
}

sf::Vector2f Player::getVecVelocityGoal() const
{
	return vecVelocityGoal;
}

sf::Vector2f Player::getPosition() const
{
	return shape.getPosition();
}

sf::FloatRect Player::getGlobalBounds() const
{
	return shape.getGlobalBounds();
}


sf::Color Player::getOutlineColor() const
{
	return OutlineColor;
}

sf::CircleShape Player::getShape() const
{
	return this->shape;
}



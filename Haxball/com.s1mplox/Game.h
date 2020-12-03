#pragma once

#include <math.h>
#include <sstream>


#include "Ball.h"
#include "Player.h"
#include "Collision.h"
#include "hitBoxMap.h"
#include "Stakes.h"
#include "Goal.h"
#include "Scorebar.h"
#include "WinTitle.h"


class Game
{
	private:

		const int W = 932;
		const int H = 416;

		sf::RenderWindow* win;
		sf::Texture tex;
		sf::Sprite spr;
		sf::Font font;
		sf::Text text;

		sf::Time time;
		sf::Clock clock;
		sf::Clock clockGameTime;

		
	
	    int pointRed;
	    int pointBlue;

		float dt = 0.f;

		//Czas gry
		double czasMinuty = 0;
		double czasSekundy = 0;
		double czasMilisekundy = 0;
		double czasMicrosekundy = 0;

		bool isScored = false;
		float maxTime;

		sf::Color colorRed = sf::Color(229, 110, 86);
		sf::Color colorBlue = sf::Color(86, 137, 229);
		
		Ball ball;

		WinTitle redtitle, bluetitle;

		Player player = Player("Gracz 1", colorRed , 150.f, 208.f);
		Player playerBlue = Player("Gracz 2", colorBlue, 770.f, 208.f);
		Collision collision;
		hitBoxMap map;
		Stakes stake;
		Goal goal;
		Scorebar scorebar;


		bool deleteMenuSprites;
		bool deleteGameSprites;
		bool onkeyHold;

		sf::Sprite MenuSprite;
		sf::Sprite button;
		sf::Texture texture[2];

		sf::Vector2f mousePosition;

	
		sf::String player_input;
		sf::Font fontArial;
		sf::Text textFont;

		void initVariables();
		void updateBallCollision(float& deltatime);	
		void updatePlayerCollision(float& deltatime);
		void updateStakeCollision();
		void updateGui();
		
	

	public:
		Game();
		virtual ~Game();

	    virtual void update();
	    virtual void render();


		bool isRunning() const;
		



};


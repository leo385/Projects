#include "Game.h"
#include "SFML/Network.hpp"

int main()
{
	Game gra; //Osobny proces


		while (gra.isRunning())
		{
			gra.update();
			gra.render();
		}
		
	return 0;
}
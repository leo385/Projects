#include "Game.h"


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
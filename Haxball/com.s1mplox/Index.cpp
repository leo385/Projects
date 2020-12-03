#include "Game.h"
#include "SFML/Network.hpp"

int var;
sf::TcpSocket socket;
sf::Socket::Status status;

int main()
{
	Game gra; //Osobny proces

	//options

	std::cout << "1.Single Player" << "\n";
	std::cout << "2.Multi Player" << "\n";
	std::cin >> var;


	switch (var)
	{
	case 1:
		while (gra.isRunning())
		{
			gra.update();
			gra.render();
		}
		break;
	case 2:
		std::cout << "Brawo wybrales opcje 2 i ona dziala" << "\n";
		//Network Sockets
		status = socket.connect("192.168.0.5", 53000);

		if (status != sf::Socket::Done)
		{
			//error
			std::cout << "Error" << "\n";
			
		}
		else {
			std::cout << "Udalo sie :)" << "\n";

			
		}
		break;
	default:
		std::cout << "Nie ma takiej opcji" << "\n";
		break;

	}
	return 0;
}
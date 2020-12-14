#pragma once

#include <iostream>
#include <string>

#include "Player.h"



class Connect
{
private:
	sf::TcpSocket socket;
	std::string msg = "Connected to: ";
	unsigned short port;

	char buffer[2000];
	std::size_t received;

	char connectionType;


public:
	Connect(const sf::IpAddress *address, unsigned short port);
	~Connect();

	void failConnection() { std::cout << "FAIL CONNECTED!" << "\n"; }
};


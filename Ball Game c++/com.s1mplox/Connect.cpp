#include "Connect.h"

Connect::Connect(const sf::IpAddress* address, unsigned short port) : port(port)
{
	std::cout << "Adres IP Serwera: " << *address << "\n";
	std::cout << "Enter s for server, Enter c for client" << "\n";
	std::cin >> this->connectionType;

	if (this->connectionType == 's' || this->connectionType == 'S')
	{
		sf::TcpListener listener;
		listener.listen(port);
		listener.accept(this->socket);
		this->msg += "Server";
	}
	else if (connectionType == 'c' || connectionType == 'C')
	{
		this->socket.connect(*address, port);
		this->msg += "Client";
	}

	this->socket.send(msg.c_str(), msg.length() + 1);

	this->socket.receive(this->buffer, sizeof(this->buffer), this->received); //Received Packets from Clients
	std::cout << this->buffer << "\n";

}


Connect::~Connect()
{
}

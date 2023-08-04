#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>

#define logl(x) std::cout << x << std::endl;
#define server "172.27.139.16"


int main() {
	
	sf::TcpSocket client;
	sf::TcpSocket::Status status = client.connect(server, 53000);
	if (status != sf::TcpSocket::Done) {
		return -1;
	}
	
	sf::Packet packet;
	
	sf::Uint16 hw[10];
	for (int i = 0; i < 10; i++) {
		hw[i] = i;
		packet << hw[i];
		client.send(packet);
	}

	return 0;
}		
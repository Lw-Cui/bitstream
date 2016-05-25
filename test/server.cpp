#include <iostream>
#include <bitstream.hpp>
#include <netstream.hpp>
#include <thread>
using namespace bit;
using namespace std;

void startServe(short connfd) {
	instream nin(connfd);
	bool b; 
	nin >> b; cout << b << endl;
	nin >> b; cout << b << endl;
	char a; 
	while (nin >> a) cout << static_cast<unsigned>(a) << endl;
}

int main(int argc, char *argv[]) {
	unsigned short port = 2000;
	if (argc == 2) sscanf(argv[1], "%hu", &port);
	try {
		while(true) 
			std::thread(startServe, Server::getConnfd(port)).detach();
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
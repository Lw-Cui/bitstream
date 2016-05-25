#include <iostream>
#include <bitstream.hpp>
#include <netstream.hpp>
using namespace bit;
using namespace std;

int main() {
	onstream nout("localhost", 2000);
	nout << true << false;
	for (int i = 0; i < 100; i++) nout << static_cast<char>(i);
	return 0;
}
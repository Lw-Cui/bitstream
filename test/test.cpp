#include <iostream>
#include <bitstream.hpp>
#include <netstream.hpp>
using namespace bit;
using namespace std;

int main() {
	obstream bout("sample.bin");
	bout << 'a' << 'b' << 'c' << 'd' << 'j';
	bout.close();

	ibstream bin("sample.bin");
	char tmp;
	while (bin >> tmp) cout << tmp << endl;
	bin.close();

	return 0;
}
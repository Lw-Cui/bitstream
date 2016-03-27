#include "header/bitstream.hpp"
using namespace bit;
using namespace std;

int main() {
	obstream bout("sample.bin");
	bout.write_byte('a');
	bout.write_byte('b');
	bout.write_byte('c');
	bout.write_byte('d');
	bout.write_byte('e');
	bout.write_byte('f');
	bout.write_byte('g');
	bout.write_byte('h');
	bout.write_byte('i');
	bout.write_bit(1);
	bout.write_bit(0);
	bout.close();
	ibstream bin("sample.bin");
	for (int i = 0; i < 9; i++)
		cout << bin.read_byte() << endl;
	cout << bin.read_bit() << endl;
	cout << bin.read_bit() << endl;
	if (!bin) cout << "pass" << endl;
	bin.close();
	return 0;
}
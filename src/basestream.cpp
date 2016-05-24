#include <basestream.hpp>
using namespace bit;
using namespace std;

bool iBaseStream::read_bit() {
	if (!(cnt % SIZE)) read_buffer();
	return buffer[cnt++ % SIZE];
}

 char iBaseStream::read_byte() {
	bitset<CHAR_BIT> tmp;
	for (int i = 0; i < CHAR_BIT; i++)
		tmp[i] = read_bit();
	return static_cast<char>(tmp.to_ulong());
}

iBaseStream &iBaseStream::read_bit(bool &b) {
	if (cnt < sum) b = read_bit();
	else valid = false;
	return *this;
}

iBaseStream &iBaseStream::read_byte(char &c) {
	if (cnt < sum) c = read_byte();
	else valid = false;
	return *this;
}

oBaseStream &oBaseStream::write_byte(char data) {
	bitset<CHAR_BIT> tmp(data);
	for (int i = 0; i < CHAR_BIT; i++)
		write_bit(tmp[i]);
	return *this;
}

oBaseStream& oBaseStream::write_bit(bool data) {
	buffer[cnt++ % SIZE] = data;
	if (!(cnt % SIZE)) write_buffer();
	return *this;
}

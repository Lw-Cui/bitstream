#include "header/bitstream.hpp"
using namespace bit;
using namespace std;

ibstream::ibstream(const string &f):cnt(0) {open(f);}
ibstream::~ibstream() {if (fin.is_open()) close();}
ibstream::operator bool() {
	return cnt != sum;
}
bool ibstream::read_bit() {
	if (!(cnt % SIZE)) read_buffer();
	return buffer[cnt++ % SIZE];
}

unsigned char ibstream::read_byte() {
	bitset<CHAR_BIT> tmp;
	for (int i = 0; i < CHAR_BIT; i++)
		tmp[i] = read_bit();
	return static_cast<unsigned char>(tmp.to_ulong());
}
void ibstream::open(const string &f) {
	fin.open(f, ios::binary | ios::in);
	fin.read(reinterpret_cast<char *>(&sum), sizeof(sum));
}
void ibstream::close() {fin.close();}
void ibstream::read_buffer() {
	unsigned long tmp;
	fin.read(reinterpret_cast<char *>(&tmp), sizeof(tmp));
	buffer = bitset<SIZE>(tmp);
}

obstream::obstream(const string &f):cnt(0) {open(f);}
obstream::~obstream() {if (fout.is_open()) close();}
void obstream::open(const string &f) {
	fout.open(f, ios::binary | ios::out);
	write_buffer();
}
void obstream::write_byte(unsigned char data) {
	bitset<CHAR_BIT> tmp(data);
	for (int i = 0; i < CHAR_BIT; i++)
		write_bit(tmp[i]);
}
void obstream::write_bit(bool data) {
	buffer[cnt++ % SIZE] = data;
	if (!(cnt % SIZE)) write_buffer();
}
void obstream::close() {
	write_buffer();
	fout.seekp(ios_base::beg);
	fout.write(reinterpret_cast<const char*>(&cnt), sizeof(cnt));
	fout.close();
}
void obstream::write_buffer() {
	unsigned long tmp = buffer.to_ulong();
	fout.write(reinterpret_cast<const char*>(&tmp), sizeof(tmp));
	buffer.reset();
}

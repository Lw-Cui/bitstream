#include <bitstream.hpp>
using namespace bit;
using namespace std;

void ibstream::open(const string &f) {
	fin.open(f, ios::binary | ios::in);
	fin.read(reinterpret_cast<char *>(&sum), sizeof(sum));
	if (sum) valid = true;
}

void ibstream::read_buffer() {
	unsigned long tmp;
	fin.read(reinterpret_cast<char *>(&tmp), sizeof(tmp));
	buffer = bitset<SIZE>(tmp);
}

void obstream::open(const string &f) {
	fout.open(f, ios::binary | ios::out);
	write_buffer();
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

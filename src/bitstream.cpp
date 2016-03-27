#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
using namespace std;
class obstream {
	static const int SIZE = 32;
	static const int CHAR_BIT = 8;
public:
	obstream(const string &f):cnt(0) {open(f);}
	~obstream() {if (fout.is_open()) close();}
	void open(const string &f) {
		fout.open(f, ios::binary | ios::out);
		write_buffer();
	}
	void write_byte(unsigned char data) {
		bitset<CHAR_BIT> tmp(data);
		for (int i = 0; i < CHAR_BIT; i++)
			write_bit(tmp[i]);
	}
	void write_bit(bool data) {
		buffer[cnt++ % SIZE] = data;
		if (!(cnt % SIZE)) write_buffer();
	}
	void close() {
		write_buffer();
		fout.seekp(ios_base::beg);
		fout.write(reinterpret_cast<const char*>(&cnt), sizeof(cnt));
		fout.close();
	}
private:
	void write_buffer() {
		unsigned long tmp = buffer.to_ulong();
		fout.write(reinterpret_cast<const char*>(&tmp), sizeof(tmp));
		buffer.reset();
	}
	unsigned long cnt;
	bitset<SIZE> buffer;
	ofstream fout;
};

int main() {
	obstream bout("sample.bin");
	bout.write_byte('a');
	bout.write_byte('b');
	bout.write_byte('c');
	bout.write_byte('d');
	bout.write_byte('e');
	bout.write_byte('f');
	bout.write_byte('g');
	bout.close();
	ibstream bin("sample.bin");
	cout << bin.sum << endl;
	bin.close();
	return 0;
}
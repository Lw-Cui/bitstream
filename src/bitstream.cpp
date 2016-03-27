#include <iostream>
#include <cstdio>
#include <bitset>
#include <fstream>
#include <string>
using namespace std;

class ibstream {
	static const int SIZE = 32;
	static const int CHAR_BIT = 8;
public:
	ibstream(const string &f):cnt(0) {open(f);}
	~ibstream() {if (fin.is_open()) close();}
	operator bool() {
		return cnt != sum;
	}
	bool read_bit() {
		if (!(cnt % SIZE)) read_buffer();
		return buffer[cnt++ % SIZE];
	}
	unsigned char read_byte() {
		bitset<CHAR_BIT> tmp;
		for (int i = 0; i < CHAR_BIT; i++)
			tmp[i] = read_bit();
		return static_cast<unsigned char>(tmp.to_ulong());
	}
	void open(const string &f) {
		fin.open(f, ios::binary | ios::in);
		fin.read(reinterpret_cast<char *>(&sum), sizeof(sum));
	}
	void close() {fin.close();}
private:
	void read_buffer() {
		unsigned long tmp;
		fin.read(reinterpret_cast<char *>(&tmp), sizeof(tmp));
		buffer = bitset<SIZE>(tmp);
	}
	unsigned long sum;
	unsigned long cnt;
	bitset<SIZE> buffer;
	ifstream fin;
};

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
	bin.close();
	return 0;
}
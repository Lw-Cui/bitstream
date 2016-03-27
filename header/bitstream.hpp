#ifndef _BITSTREAM_H_
#define _BITSTREAM_H_
#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
namespace bit {
	static const int SIZE = 32;
	static const int CHAR_BIT = 8;

	class ibstream {
	public:
		ibstream(const std::string &f);
		~ibstream();
		operator bool();
		bool read_bit();
		unsigned char read_byte();
		void open(const std::string &f);
		void close();
	private:
		void read_buffer();
		unsigned long sum;
		unsigned long cnt;
		std::bitset<SIZE> buffer;
		std::ifstream fin;
	};

	class obstream {
	public:
		obstream(const std::string &f);
		~obstream();
		void open(const std::string &f);
		void write_byte(unsigned char data);
		void write_bit(bool data);
		void close();
	private:
		void write_buffer();
		unsigned long cnt;
		std::bitset<SIZE> buffer;
		std::ofstream fout;
	};
}

#endif
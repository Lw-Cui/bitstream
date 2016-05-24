_Pragma ("once");
#include <bitset>

namespace bit {

	static const int SIZE = 32;
	static const int CHAR_BIT = 8;

	class iBaseStream {
	public:
		iBaseStream():sum{1 << SIZE - 2}, cnt{0}, valid{true} {}
		virtual ~iBaseStream(){}
		iBaseStream(const iBaseStream &) = delete;
		iBaseStream(iBaseStream &&) = delete;
		iBaseStream& operator=(const iBaseStream &) = delete;

		operator bool() {return valid;}
		iBaseStream &read_bit(bool &);
		iBaseStream & read_byte(char&);

	protected:
		virtual void read_buffer() = 0;
		bool read_bit();
		char read_byte();

		std::bitset<SIZE> buffer;
		unsigned long sum;
		unsigned long cnt;
		bool valid;
	};

	class oBaseStream {
	public:
		oBaseStream():cnt{0} {}
		virtual ~oBaseStream(){}
		oBaseStream(const oBaseStream &) = delete;
		oBaseStream(oBaseStream &&) = delete;
		oBaseStream& operator=(const oBaseStream &) = delete;

		oBaseStream &write_bit(bool data);
		oBaseStream &write_byte(char data);

	protected:
		virtual void write_buffer() = 0;
		std::bitset<SIZE> buffer;
		unsigned long cnt;
	};

	inline iBaseStream& operator>> 
		(iBaseStream& bin, char& c) {return bin.read_byte(c);}
	inline iBaseStream& operator>> 
		(iBaseStream& bin, bool& b) {return bin.read_bit(b);}
	inline oBaseStream& operator<< 
		(oBaseStream& bout, const char &c) {return bout.write_byte(c);}
	inline oBaseStream& operator<< 
		(oBaseStream& bout, const bool &b) {return bout.write_bit(b);}
}
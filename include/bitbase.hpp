_Pragma ("once");
#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
namespace bit {
	class IBaseStream {
	public:
		virtual ~IBaseStream(){};

		virtual IBaseStream& read_bit(bool&) = 0;
		virtual IBaseStream& read_byte(char&) = 0;

		virtual void open(const std::string&) = 0;
		virtual void close() = 0;

		virtual operator bool() = 0;
	};

	class OBaseStream {
	public:
		virtual ~OBaseStream(){};

		virtual OBaseStream& write_bit(bool) = 0;
		virtual OBaseStream& write_byte(char) = 0;

		virtual void open(const std::string&) = 0;
		virtual void close() = 0;
	};

	inline IBaseStream& operator>> 
		(IBaseStream& bin, char& c) {return bin.read_byte(c);}
	inline IBaseStream& operator>> 
		(IBaseStream& bin, bool& b) {return bin.read_bit(b);}
	inline OBaseStream& operator<< 
		(OBaseStream& bout, const char &c) {return bout.write_byte(c);}
	inline OBaseStream& operator<< 
		(OBaseStream& bout, const bool &b) {return bout.write_bit(b);}
}
_Pragma ("once");
#include <bitbase.hpp>
namespace bit {
	static const int SIZE = 32;
	static const int CHAR_BIT = 8;

	class ibstream: public IBaseStream {
	public:
		ibstream(const std::string &f);
		~ibstream();

		operator bool()override;

		ibstream &read_bit(bool &) override;
		ibstream & read_byte(char&) override;

		void open(const std::string &f) override;
		void close() override;

	private:
		bool read_bit();
		char read_byte();
		void read_buffer();
		bool valid;
		unsigned long sum;
		unsigned long cnt;
		std::bitset<SIZE> buffer;
		std::ifstream fin;
	};

	class obstream: public OBaseStream {
	public:
		obstream(const std::string &f);
		~obstream();

		obstream &write_bit(bool data) override;
		obstream &write_byte(char data) override;

		void open(const std::string &f) override;
		void close() override;
		
	private:
		void write_buffer();
		unsigned long cnt;
		std::bitset<SIZE> buffer;
		std::ofstream fout;
	};
}
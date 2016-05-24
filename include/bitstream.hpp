_Pragma ("once");
#include <string>
#include <fstream>
#include <basestream.hpp>

namespace bit {
	class ibstream final: public iBaseStream {
	public:
		ibstream(const std::string &f) {open(f);}
		~ibstream() {if (fin.is_open()) close();}
		void open(const std::string &f);
		void close() {fin.close();}

	private:
		void read_buffer();
		std::ifstream fin;
	};

	class obstream final: public oBaseStream {
	public:
		obstream(const std::string &f) {open(f);}
		~obstream(){if (fout.is_open()) close();}
		void open(const std::string &f); 
		void close();

	private:
		void write_buffer();
		std::ofstream fout;
	};
}
_Pragma ("once");
#include <NetService.hpp>
#include <basestream.hpp>
#include <json.hpp>

namespace bit {
	static const int LEN = 10;

	class instream final: public iBaseStream {
	public:
		instream(int port)
			:communicator{port}, index{-1} {data["EOF"] = false;}
		~instream(){}

	private:
		void read_buffer();
		NetService communicator; int index;
		nlohmann::json data;
	};

	class onstream final: public oBaseStream {
	public:
		onstream(const std::string &hostname, int port)
			:communicator{hostname, port}{data["EOF"] = false;}
		~onstream();
		
	private:
		void write_buffer();
		NetService communicator;
		nlohmann::json data;
	};

}
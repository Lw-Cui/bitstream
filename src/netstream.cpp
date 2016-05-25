#include <netstream.hpp>
using namespace std;
using namespace bit;
using namespace nlohmann;

void instream::read_buffer() {
	if (index == -1 || static_cast<unsigned>(index) == data["array"].size()) {
		string str; communicator.read_str(str); data = json::parse(str); index = 0;
		if (data["EOF"] == true) sum = data["len"];
	}
	buffer = bitset<SIZE>(static_cast<unsigned>(data["array"][index++]));
}

void onstream::write_buffer() {
	data["array"].push_back(static_cast<unsigned>(buffer.to_ulong()));
	if (data["array"].size() >= LEN) {
		communicator.write_str(data.dump());
		data["array"].clear(); buffer.reset();
	}
}

onstream::~onstream() {
	data["EOF"] = true; data["len"] = cnt;
	data["array"].push_back(static_cast<unsigned>(buffer.to_ulong()));
	communicator.write_str(data.dump());
}
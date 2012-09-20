#include "uuid.h"
#include <ctime>

namespace {
	std::uniform_int_distribution<int> distribution(0,std::numeric_limits<uint32_t>::max());
	std::mt19937 engine; // Mersenne twister MT19937
	bool is_inited=false;
};

UUID::UUID() {
	if(!is_inited) {
		engine.seed(std::time(NULL));
		is_inited=true;
	}
	for(int i=0;i<4;i++) {
		id[i] = distribution(engine);
	}
	id[2] = ((id[2]&0xFFFF0FFF)|0x00004000);
	id[1] = ((id[1]&0x3FFFFFFF)|0x80000000);
}

bool UUID::operator==(const UUID& other) const{
	bool ret_val = true;
	for(int i=0;i<4;i++) {
		ret_val &= (other.id[i] == id[i]);
	}
	return ret_val;
}

std::ostream& operator<<(std::ostream &stream,const UUID& id) {
	stream << std::hex;
	stream << id.id[0] << "-";
	stream << id.id[1] << "-";
	stream << id.id[2] << "-";
	stream << id.id[3];
	stream << std::dec;
	return stream;
}

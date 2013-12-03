#include "uuid.h"
#include "randomword.h"
#include <cassert>

const UUID nullconstant;

namespace {
	RandomWord wordgen;
};

UUID::UUID() {

	for(int i=0;i<4;i++) {
		id[i] = wordgen();
	}

	id[2] = ((id[2]&0xFFFF0FFF)|0x00004000);
	id[1] = ((id[1]&0x3FFFFFFF)|0x80000000);
}

UUID::UUID(const UUID &other) {
	for(uint8_t i=0;i<4;i++) {
		id[i] = other.id[i];
	}
}

bool UUID::operator==(const UUID& other) const{
	bool ret_val = true;
	for(int i=0;i<4;i++) {
		ret_val &= (other.id[i] == id[i]);
	}
	return ret_val;
}

uint32_t UUID::get(size_t i) const {
	assert(i<4);
	return id[i];
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

namespace std {
	size_t hash<UUID>::operator()(const UUID &id ) const {
		size_t hash=0;
		const int SIZE_T_MAX = sizeof(size_t)*8;
		const int increment = SIZE_T_MAX/4;

		for(int i=0;i<4;i++) {
			hash =  hash ^ (id.id[i] << (increment*i - sizeof(uint32_t))*8);
		}
		return hash;
	}
};

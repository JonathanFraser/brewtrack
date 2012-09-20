#ifndef UUID_H
#define UUID_H
#include <stdint.h>
#include <random>
#include <ostream>

class UUID {
	private:
		uint32_t id[4];
	public:
		UUID();
		bool operator==(const UUID &other) const;
		friend std::ostream& operator<<(std::ostream &stream, const UUID& id);
};

#endif

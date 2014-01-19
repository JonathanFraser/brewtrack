#include "randomword.h"

RandomWord::RandomWord() {
	std::random_device rd;
	std::uniform_int_distribution<uint32_t> distribution(0,std::numeric_limits<uint32_t>::max());
	std::mt19937 engine; // Mersenne twister MT19937
	engine.seed(rd());
}

uint32_t RandomWord::operator()() {
	return distribution(engine);
}

#ifndef RANDOMWORD_H
#define RANDOMWORD_H
#include <stdint.h>
#include <limits>
#include <random>


class RandomWord {
		private:
			std::random_device rd;
			std::uniform_int_distribution<uint32_t> distribution;
			std::mt19937 engine; // Mersenne twister MT19937
		public:
			RandomWord();
			uint32_t operator()();
};
#endif

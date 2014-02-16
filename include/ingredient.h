#ifndef INGREDIENT_H_
#define INGREDIENT_H_
#include <cstdint>
#include <cstring>
#include "storable.h"

enum class Unit : std::uint64_t {
	AAU,
	LITER,
	OZ
};

class Ingredient : public Storable {
	public:
		Ingredient(const DatabaseRef);
		Ingredient(const UUID& id, const DatabaseRef);
		Ingredient(const Ingredient&);
		uint64_t getQuantity() const;
		Unit getUnit() const;
		std::string getName() const;

		void setQuantity(uint64_t);
		void setUnit(Unit);
		void setName(std::string);
};

#endif

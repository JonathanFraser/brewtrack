#include "ingredient.h"

const std::string INGREDIENT_TYPE="INGREDIENT";
const std::string QUANTITY="QUANTITY";
const std::string UNIT_VAL="UNIT";
const std::string NAME = "NAME";

Ingredient::Ingredient(const DatabaseRef sink) : Storable(sink,INGREDIENT_TYPE){
}

Ingredient::Ingredient(const UUID &id, const DatabaseRef sink) : Storable(id,sink) {
}

Ingredient::Ingredient(const Ingredient &other) : Storable(other) {
}

uint64_t Ingredient::getQuantity() const {
	return retrieveInt(QUANTITY);
}

Unit Ingredient::getUnit() const {
	return static_cast<Unit>(retrieveInt(UNIT_VAL));
}

std::string Ingredient::getName() const {
	return retrieveString(NAME);
}

void Ingredient::setQuantity(uint64_t amount) {
	stashInt(QUANTITY,amount);
}

void Ingredient::setUnit(Unit unit) {
	stashInt(UNIT_VAL, static_cast<uint64_t>(unit));
}

void Ingredient::setName(std::string name) {
	stashString(NAME,name);
}

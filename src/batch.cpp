#include "batch.h"

Batch::Batch() : timestamp(time(0)) {
}

const std::string& Batch::getName() const {
	return name;
}

const std::string& Batch::getDescription() const {
	return description;
}

time_t Batch::getTimestamp() const {
	return timestamp;
}

RecipeRef Batch::getRecipe() const {
	return recipe;
}


void Batch::setName(const std::string &text) {
		name = text;
}

void Batch::setDescription(const std::string &text) {
		description = text;
}

UUID Batch::getUUID() {
	return id;
}

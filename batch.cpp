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

UUID Batch::getRecipeUUID() const {
	return recipe_id;
}

UUID Batch::getUUID() const {
	return id;
}


void Batch::setName(const std::string &text) {
	if(text != name) {
		isSaved=false;
		name = text;
	}
}

void Batch::setDescription(const std::string &text) {
	if(text != description) {
		isSaved=false;
		description = text;
	}
}


void Batch::setUUID(const UUID &uuid) {
	id = uuid;
}

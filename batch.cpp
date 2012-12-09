#include "batch.h"

const std::string& Batch::getName() {
	return name;
}

const std::string& Batch::getDescription() {
	return description;
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

UUID Batch::getUUID() const {
	return id;
}

void Batch::setUUID(const UUID &uuid) {
	id = uuid;
}

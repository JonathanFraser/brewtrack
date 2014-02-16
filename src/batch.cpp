#include "batch.h"

const std::string BATCH_TYPE = "BATCH";
const std::string RECIPE_ID = "RECIPE ID";
const std::string DESC = "DESCRIPTION";
const std::string NAME = "NAME";

Batch::Batch(const Recipe &recipe) : Storable(recipe.getSink(),BATCH_TYPE){
	stashID(RECIPE_ID,recipe.getUUID());
}

const std::string& Batch::getName() const {
	return retrieveString(NAME);
}

const std::string& Batch::getDescription() const {
	return retrieveString(DESC);
}


void Batch::setName(const std::string &text) {
 stashString(NAME,text);
}

void Batch::setDescription(const std::string &text) {
	stashString(DESC,text);
}

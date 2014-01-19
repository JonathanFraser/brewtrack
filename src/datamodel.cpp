#include "datamodel.h"

void DataModel::setPrimaryDatabase(DatabaseRef database) {
	primary_database = database;
}

void DataModel::addBatch(BatchRef batch) {
	primary_database->addBatch(batch);
}

BatchRef DataModel::getBatchByID(const UUID &id) {
	return primary_database->getBatchByID(id);
}

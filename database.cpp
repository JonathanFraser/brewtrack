#include "database.h"
#include <utility>

using namespace std;

void Database::addBatch(BatchRef batch) {
		auto stuff = make_pair(batch->getUUID(),batch);
		batch->isSaved = false;
		batches.insert(stuff);
}

void Database::setDataSource(DataSourceRef sourceref) {
	source = sourceref;
}


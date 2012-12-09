#include "datasource.h"

void DataSource::setBatchUUID(BatchRef batch, const UUID &id) {
	batch->setUUID(id);
}

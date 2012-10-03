#include "sqlbase.h"

void SQLBase::addBatch(BatchRef batch) {
}

BatchRef SQLBase::getBatchByID(const UUID &id) {
	return std::shared_ptr<Batch>((Batch*)0);
}

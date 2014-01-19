#include "memorybase.h"
#include <utility>
#include <iostream>

void MemoryBase::addBatch(BatchRef batch) {
	auto ptr = batches.find(batch->getUUID());
	if(ptr == batches.end()) {
		batches.insert(std::make_pair(batch->getUUID(),batch));
	} else {
		batches[batch->getUUID()] = batch;
	}
}

BatchRef MemoryBase::getBatchByID(const UUID &id) {
	if(batches.count(id)) {
		return batches[id];
	} else {
		return std::shared_ptr<Batch>((Batch*)0);
	}
}

#ifndef MEMORY_BASE_H_
#define MEMORY_BASE_H_

#include "database.h"
#include <unordered_map>

class MemoryBase : public Database {
	public:
		void addBatch(BatchRef batch);
		BatchRef getBatchByID(const UUID &id);
	private:
		std::unordered_map<UUID,BatchRef> batches;		
};

#endif

#ifndef DATABASE_H_
#define DATABASE_H_

#include <unordered_map>
#include <memory>
#include <utility>
#include "batch.h"
#include "datasource.h"
#include "uuid.h"

class Database {
	private:
		DataSourceRef source;
		std::unordered_map<UUID,BatchRef> batches;
	public:
		void addBatch(BatchRef);
		void setDataSource(DataSourceRef sourceref);
};

#endif

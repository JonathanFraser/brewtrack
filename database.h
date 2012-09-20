#ifndef DATABASE_H_
#define DATABASE_H_

#include <unordered_map>
#include <memory>
#include <utility>
#include "batch.h"
#include "datasource.h"
#include "uuid.h"

class Database {
	std::shared_ptr<DataSource> source;
	std::unordered_map<UUID,std::pair<bool,std::shared_ptr<Batch>>> batches;

};

#endif

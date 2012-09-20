#ifndef DATASOURCE_H_
#define DATASOURCE_H_

#include "batch.h"
#include <memory>

class DataSource {
	public:
		virtual void saveBatch(BatchRef batchReference) = 0;
};

typedef std::shared_ptr<DataSource> DataSourceRef;

#endif

#ifndef DATASOURCE_H_
#define DATASOURCE_H_

#include "batch.h"

class DataSource {
	public:
		virtual void saveBatch(BatchRef batchReference) = 0;
};
#endif

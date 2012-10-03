#ifndef DATASOURCE_H_
#define DATASOURCE_H_

#include "batch.h"
#include "uuid.h"

class DataSource {
	public:
		virtual BatchRef getBatchByID(const UUID &id) = 0;
};

#endif

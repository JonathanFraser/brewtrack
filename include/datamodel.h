#ifndef DATAMODEL_H_
#define DATAMODEL_H_

#include "database.h"
#include "batch.h"

class DataModel {
	public:
		void setPrimaryDatabase(DatabaseRef database);
		void addBatch(BatchRef);
		BatchRef getBatchByID(const UUID &);
	private:
		DatabaseRef primary_database;
};

#endif

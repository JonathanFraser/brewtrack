#ifndef DATAMODEL_H_
#define DATAMODEL_H_

#include "database.h"
#include "batch.h"

class DataModel {
	public:
		void setPrimaryDatabase(DatabaseRef database);
		
	private:
		DatabaseRef primary_database;
};

#endif

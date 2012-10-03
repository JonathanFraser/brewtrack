#ifndef SQLBASE_H_
#define SQLBASE_H_
#include "database.h"

class SQLBase : public Database {
	public:
		void addBatch(BatchRef batch);
		BatchRef getBatchByID(const UUID &id);
	protected:
		virtual void initDB() =0;
		virtual void executeQuery(const std::string &statment) =0;
};

#endif

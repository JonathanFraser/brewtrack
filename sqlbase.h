#ifndef SQLBASE_H_
#define SQLBASE_H_
#include <memory>
#include <string>
#include <tntdb/connection.h>
#include "database.h"

class SQLBase : public Database {
	public:
		SQLBase(const std::string &connection_string);
		void addBatch(BatchRef batch);
		BatchRef getBatchByID(const UUID &id);
	private:
		void initDB();
		void upgradeVersion(size_t old_version);
		tntdb::Connection dbconn;
};

#endif

#ifndef SQL_LITE_SOURCE_H_
#define SQL_LITE_SOURCE_H_

#include "batch.h"
#include "sqlbase.h"
#include <string>

class sqlite3;

class SQLiteSource : public SQLBase {
	public:
		SQLiteSource(std::string filename);
		~SQLiteSource();
	protected:
		virtual void initDB();
		virtual void executeQuery(const std::string &statment);
	private:
		sqlite3* db;
};


#endif

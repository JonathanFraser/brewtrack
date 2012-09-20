#ifndef SQL_LITE_SOURCE_H_
#define SQL_LITE_SOURCE_H_

#include "datasource.h"
#include <string>

class sqlite3;

class SQLiteSource : public DataSource {
	public:
		SQLiteSource(std::string filename);
		~SQLiteSource();
		void saveBatch(BatchRef batchReference);
	private:
		sqlite3* db;
		bool isDBReady();
		void initDB();
};


#endif

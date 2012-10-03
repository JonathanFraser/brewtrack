#ifndef SQL_LITE_SOURCE_H_
#define SQL_LITE_SOURCE_H_

#include <string>
#include "batch.h"

class sqlite3;

class SQLiteSource{
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

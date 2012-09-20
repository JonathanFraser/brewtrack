#include "sqlitesource.h"
#include <sqlite3.h>

SQLiteSource::SQLiteSource(std::string filename) {
	sqlite3_open(filename.c_str(),&db);
}

void SQLiteSource::saveBatch(BatchRef batchReference) {

}

bool SQLiteSource::isDBReady() {	
#warning non-functional
return false;
}

void SQLiteSource::initDB() {
}

SQLiteSource::~SQLiteSource() {
	sqlite3_close(db);
}


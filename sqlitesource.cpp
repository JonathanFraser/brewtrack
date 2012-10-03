#include "sqlitesource.h"
#include <sqlite3.h>
#include <cassert>

SQLiteSource::SQLiteSource(std::string filename) {
	sqlite3_open(filename.c_str(),&db);
}

void SQLiteSource::initDB() {
	assert(false);
}

void SQLiteSource::executeQuery(const std::string &statment) {
	assert(false);
}

SQLiteSource::~SQLiteSource() {
	sqlite3_close(db);
}


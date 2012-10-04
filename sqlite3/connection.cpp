#include "connection.h"

using namespace Sqlite3pp;

Connection::Connection(const std::string &filename) {
	switch(sqlite3_open(filename.c_str(),&connection)) {
		/* throw various errors here */
	}
}

Connection::Connection(const std::string &filename, int flags, const std::string &vfs_module) {
	switch(sqlite3_open_v2(filename.c_str(),&connection,flags,vfs_module.c_str())) {
		/* throw various errors here */
	}
}

Connection::~Connection() {
	switch(sqlite3_close(connection)) {
		/*throw various errors here*/
	}
}


Statement Connection::prepareStatement(std::string &query) {
	const char *temp;
	sqlite3_stmt *stmt;
	switch(sqlite3_prepare_v2(connection,query.c_str(),query.size(),&stmt,&temp)) {
	/* errors errors */
}
	std::string new_str(temp);
	query = new_str;
	Statement statement(stmt);
	return statement;
}

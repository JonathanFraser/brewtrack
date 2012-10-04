#include "statement.h"

using namespace Sqlite3pp;

Statement::Statement(sqlite3_stmt *stmt_ptr) {
	ptr = stmt_ptr;
}

Statement::Statement(Statement &other) {
	ptr = other.ptr;
	other.ptr = NULL;
}

Statement::~Statement() {
	switch(sqlite3_finalize(ptr)) {
		/*errors here */
	}
}

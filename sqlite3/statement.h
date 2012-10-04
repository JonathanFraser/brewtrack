#ifndef STATEMENT_H_
#define STATEMENT_H_

#include <string>
#include <vector>
#include <stdint.h>
#include <sqlite3.h>


namespace Sqlite3pp {
	class Connection;
	class Statement {
		public:
			Statement(Statement &);
			~Statement();
		private:
			Statement(sqlite3_stmt *stmt_ptr);
			Statement(const Statement &) = delete;
			sqlite3_stmt *ptr;

			friend class Connection;
	};
};

#endif

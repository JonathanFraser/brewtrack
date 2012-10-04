#ifndef CONNECTION_H_
#define CONNECTION_H_

#include <string>
#include <sqlite3.h>
#include "statement.h"

namespace Sqlite3pp {
	class Connection {
		public:
			Connection(const std::string &filename);
			Connection(const std::string &filename, int flags, const std::string &vfs_module);
			~Connection();

			Statement prepareStatement(std::string &query);
		private:
			sqlite3* connection;
	};
};
#endif

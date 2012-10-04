#include "sqlite3pp.h"

int main(void) {
	Sqlite3pp::Connection conn("Test.dat");
	return 0;
}

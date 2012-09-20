#include <iostream>
#include "database.h"
#include "sqlitesource.h"
#include "uuid.h"


using namespace std;

int main(void) {
auto datasource = make_shared<SQLiteSource>("testfile.dat");
Database base;
base.setDataSource(datasource);
return 0;
}

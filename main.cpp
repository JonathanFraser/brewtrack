#include <iostream>
#include "database.h"
#include "sqlitesource.h"
#include "uuid.h"


using namespace std;

int main(void) {
auto datasource = make_shared<SQLiteSource>("testfile.dat");
Database base;
base.setDataSource(datasource);
BatchRef batch1 = make_shared<Batch>();
batch1->setName("Batch1");
batch1->setDescription("Description of Batch1");
base.addBatch(batch1);
BatchRef batch2 = make_shared<Batch>();
batch2->setName("Batch2");
batch2->setDescription("Description of Batch2");
base.addBatch(batch2);
BatchRef batch3 = make_shared<Batch>();
batch3->setName("Batch3");
batch3->setDescription("Description of Batch3");
base.addBatch(batch3);

return 0;
}

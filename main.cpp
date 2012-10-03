#include <iostream>
#include "datamodel.h"
#include "memorybase.h"

using namespace std;

int main(void) {
BatchRef batch1 = std::make_shared<Batch>();
batch1->setName("Happy Days");
batch1->setDescription("Some Test Statement");
DataModel model;
model.setPrimaryDatabase(std::make_shared<MemoryBase>());
model.addBatch(batch1);
auto batch2 = model.getBatchByID(batch1->getUUID());
std::cout << batch2->getName() << std::endl;
std::cout << batch2->getDescription() << std::endl;
return 0;
}

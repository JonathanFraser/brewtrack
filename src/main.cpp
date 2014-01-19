#include <cstdio>
#include <cassert>
#include <iostream>
#include "datamodel.h"
#include "memorybase.h"
//#include "sqlbase.h"

using namespace std;

const size_t MY_ARRAY_SIZE = 1024;

UUID ids[MY_ARRAY_SIZE];

int main(void) {
	char temp[512];
	DataModel model;
	model.setPrimaryDatabase(std::make_shared<MemoryBase>());
	//model.setPrimaryDatabase(std::make_shared<SQLBase>("sqlite:running.db"));
	for(size_t i=0;i<MY_ARRAY_SIZE;i++) {
		BatchRef batch1 = std::make_shared<Batch>();
		sprintf(temp,"Some Name: %ld",i);
		batch1->setName(temp);
		sprintf(temp,"Some Desc: %ld",i);
		batch1->setDescription(temp);
		ids[i] = batch1->getUUID();
		model.addBatch(batch1);
		std::cout << "Adding batch: " << i << std::endl;
	}
	for(size_t i=0;i<MY_ARRAY_SIZE;i++) {
		auto batch2 = model.getBatchByID(ids[i]);
		std::cout << batch2->getName() << " - ";
		std::cout << batch2->getDescription() << std::endl;
		assert(batch2->getUUID() == ids[i]);
	}
	return 0;
}

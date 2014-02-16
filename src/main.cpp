#include <cstdio>
#include <cassert>
#include <iostream>
#include "datamodel.h"
#include "memorybase.h"

//#include "sqlbase.h"

using namespace std;

int main(void) {
	char temp[512];
	DataModel model;
	model.setPrimaryDatabase(std::make_shared<MemoryBase>());
	//model.setPrimaryDatabase(std::make_shared<SQLBase>("sqlite:running.db"));
	return 0;
}

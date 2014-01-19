#ifndef DATASINK_H_
#define DATASINK_H_

#include "batch.h"

class DataSink {
	public:
		virtual void addBatch(BatchRef batch) =0;
};

#endif

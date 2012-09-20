#ifndef SQL_LITE_SOURCE_H_
#define SQL_LITE_SOURCE_H_

#include "datasource.h"

class SQLiteSource : public DataSource {
	void saveBatch(BatchRef batchReference);	
};


#endif

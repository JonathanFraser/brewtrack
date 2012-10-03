#ifndef DATABASE_H_
#define DATABASE_H_

#include <memory>
#include "datasink.h"
#include "datasource.h"

class Database : public DataSink, public DataSource {
};

typedef std::shared_ptr<Database> DatabaseRef;

#endif

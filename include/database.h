#ifndef DATABASE_H_
#define DATABASE_H_

#include "datasource.h"
#include "uuid.h"
#include <memory>
#include <utility>

class Database : public DataSource {
	public:
		virtual void setID(const UUID &id, const std::string &type_name, const std::string &var_name,const UUID &variable)=0;
		virtual void setString(const UUID &id,const std::string &type_name,const std::string &var_name, const std::string &variable)=0;
		virtual void setInt(const UUID &id, const std::string &type_name, const std::string &var_name, uint64_t variable)=0;
		virtual void setIDList(const UUID &id, const std::string &type_name, const std::string &var_name, const std::vector<UUID>& variable)=0;
		virtual void setTime(const UUID &id, const std::string &type_name, time_t variable)=0;

};

typedef std::shared_ptr<Database> DatabaseRef;

#endif

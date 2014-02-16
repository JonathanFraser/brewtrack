#ifndef DATASOURCE_H_
#define DATASOURCE_H_

#include "uuid.h"
#include <memory>
#include <utility>
#include <unordered_map>
#include <vector>

class DataSource {
	public:
		virtual UUID getID(const UUID &id, const std::string& type_name, const std::string &var_name) const=0;
		virtual std::string getString(const UUID &id,const std::string& type_name, const std::string &var_name) const=0;
		virtual uint64_t getInt(const UUID &id,const std::string &type_name, const std::string &var_name) const=0;
		virtual std::vector<UUID> getIDList(const UUID &id, const std::string &type_name, const std::string &var_name) const=0;
		virtual time_t getTime(const UUID&, const std::string&) const=0;

};

typedef std::shared_ptr<DataSource> DataSourceRef;

#endif

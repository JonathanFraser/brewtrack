#ifndef MEMORY_BASE_H_
#define MEMORY_BASE_H_

#include "database.h"
#include <unordered_map>

typedef std::unordered_map<std::string,std::string> StringTable;
typedef std::unordered_map<std::string,uint64_t> IntTable;
typedef std::unordered_map<std::string,UUID> IDTable;
typedef std::unordered_map<std::string,std::vector<UUID>> IDsTable;

struct Object {
	time_t time;
	StringTable stable;
	IntTable itable;
	IDTable idtable;
	IDsTable idstable;
};

typedef std::unordered_map<UUID,Object> CategoryTable;

typedef std::unordered_map<std::string,CategoryTable> DataTable;

class MemoryBase : public Database {
	public:
		virtual void setID(const UUID &id, const std::string &type_name, const std::string &var_name,const UUID &variable);
		virtual void setString(const UUID &id,const std::string &type_name,const std::string &var_name, const std::string &variable);
		virtual void setInt(const UUID &id, const std::string &type_name, const std::string &var_name, uint64_t variable);
		virtual void setTime(const UUID &id, const std::string &type_name, time_t variable);
		virtual void setIDList(const UUID &id, const std::string &type_name, const std::string &var_name, const std::vector<UUID>& variable);

		virtual UUID getID(const UUID &id, const std::string& type_name, const std::string &var_name) const;
		virtual std::string getString(const UUID &id,const std::string& type_name, const std::string &var_name) const;
		virtual uint64_t getInt(const UUID &id,const std::string &type_name, const std::string &var_name)const;
		virtual time_t getTime(const UUID&, const std::string&) const;
		virtual std::vector<UUID> getIDList(const UUID &id, const std::string &type_name, const std::string &var_name) const;


	private:
		DataTable stuff;
};

#endif

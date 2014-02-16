#ifndef LOADABLE_H_
#define LOADABLE_H_

#include "datasource.h"
#include "uuid.h"
#include <ctime>
#include <unordered_map>

class Loadable {
	public:
		UUID getUUID() const;
		time_t getTimestamp() const;
		DataSourceRef getSource() const;
	protected:
		UUID id;
		Loadable(const DataSourceRef, const std::string& type);
		Loadable(const Loadable &);
		Loadable(const UUID &id, const DataSourceRef source);

		
		UUID retrieveID(const std::string &) const;
		std::string retrieveString(const std::string &) const;
		uint64_t retrieveInt(const std::string &) const;

	private:
		std::string type;
		DataSourceRef source;	
	
};

#endif

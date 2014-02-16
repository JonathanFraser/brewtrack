#include "storable.h"
#include <utility>

DatabaseRef Storable::getSink() const {
	return sink;
}

Storable::Storable(const DatabaseRef sink, const std::string &type) : Loadable(sink,type), sink(sink) {
	sink->setTime(id,type,time(0));
}

Storable::Storable(const UUID& id,const DatabaseRef sink) : Loadable(id,sink), sink(sink) {
}

Storable::Storable(const Storable &other) : Loadable(other) , sink(other.sink) {
}

void Storable::stashInt(const std::string &name, const uint64_t& num) {
	sink->setInt(id,type,name,num);
}

void Storable::stashID(const std::string &name, const UUID& id) {
	sink->setID(id,type,name,id);
}

void Storable::stashString(const std::string &name, const std::string& string) {
	sink->setString(id,type,name,string);
}



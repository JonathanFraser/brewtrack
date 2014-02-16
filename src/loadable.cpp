#include "loadable.h"

Loadable::Loadable(const DataSourceRef source, const std::string& type) : type(type), source(source) {
}

Loadable::Loadable(const Loadable& other) : id(other.id), source(other.source) {
}

Loadable::Loadable(const UUID &id, const DataSourceRef source) : id(id), source(source) {
}

UUID Loadable::getUUID() const {
	return id;
}

time_t Loadable::getTimestamp() const {
	return source->getTime(id,type);
}

DataSourceRef Loadable::getSource() const {
	return source;
}

uint64_t Loadable::retrieveInt(const std::string &name) const {
	return source->getInt(id,type,name);
}

UUID Loadable::retrieveID(const std::string &name) const {
	return source->getID(id,type,name);
}

std::string Loadable::retrieveString(const std::string &name) const {
	return source->getString(id,type,name);
}


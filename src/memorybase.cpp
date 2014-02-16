#include "memorybase.h"
#include <utility>
#include <iostream>

UUID MemoryBase::getID(const UUID &item_id, const std::string& type, const std::string &var_name) const {
	return stuff.at(type).at(item_id).idtable.at(var_name);
}
		
std::string MemoryBase::getString(const UUID& item_id,const std::string& type, const std::string &var_name) const {
	return stuff.at(type).at(item_id).stable.at(var_name);
}

uint64_t MemoryBase::getInt(const UUID& item_id,const std::string& type, const std::string &var_name) const {
	return stuff.at(type).at(item_id).itable.at(var_name);
}

std::vector<UUID> MemoryBase::getIDList(const UUID &id, const std::string &type_name, const std::string &var_name) const {
	return stuff.at(type_name).at(id).idstable.at(var_name);
}
	
time_t MemoryBase::getTime(const UUID& item_id, const std::string& type) const {
	return stuff.at(type).at(item_id).time;
}

void MemoryBase::setID(const UUID &item_id, const std::string& type, const std::string &var_name , const UUID &entry) {
	auto map = &(stuff.at(type).at(item_id).idtable);
	auto i = map->find(var_name);
	if(i != map->end()) {
		map->erase(i);
	}
	map->insert(std::make_pair(var_name,entry));
}

void MemoryBase::setString(const UUID &item_id, const std::string& type, const std::string &var_name,const std::string &entry) {
	auto map = &(stuff.at(type).at(item_id).stable);
	auto i = map->find(var_name);
	if(i != map->end()) {
		map->erase(i);
	}
	map->insert(std::make_pair(var_name,entry));
}

void MemoryBase::setInt(const UUID &item_id, const std::string& type, const std::string &var_name,uint64_t entry) {
	auto map = &(stuff.at(type).at(item_id).itable);
	auto i = map->find(var_name);
	if(i != map->end()) {
		map->erase(i);
	}
	map->insert(std::make_pair(var_name,entry));
}

void MemoryBase::setIDList(const UUID &id, const std::string &type_name, const std::string &var_name, const std::vector<UUID>& variable) {
	auto map = &(stuff.at(type_name).at(id).idstable);
	auto i = map->find(var_name);
	if(i != map->end()) {
		map->erase(i);
	}
	map->insert(std::make_pair(var_name,variable));

}

void MemoryBase::setTime(const UUID &item_id, const std::string& type, time_t time) {
	stuff[type][item_id].time = time;
}


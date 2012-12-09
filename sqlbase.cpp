#include "sqlbase.h"
#include <tntdb/connect.h>
#include <tntdb/result.h>
#include <tntdb/row.h>
#include <tntdb/value.h>
#include <cassert>
#include <iostream>

const size_t CURRENT_VER = 1;

SQLBase::SQLBase(const std::string &connection_string) : dbconn(tntdb::connect(connection_string)) {	
	initDB();
}

void SQLBase::addBatch(BatchRef batch) {
	tntdb::Statement insert = dbconn.prepare("INSERT INTO batches VALUES (:v1,:v2,:v3,:v4,:v5,:v6)");
	tntdb::Statement update = dbconn.prepare("UPDATE batches SET name=:v1, desc=:v2 WHERE key0=:v3 AND"
	                                                                                            " key1=:v4 AND"
																																															" key2=:v5 AND"
																																															" key3=:v6");
	if(getBatchByID(batch->getUUID())) {
		update.setString("v1",batch->getName());
		update.setString("v2",batch->getDescription());
		update.setInt("v3",batch->getUUID().get(0));
		update.setInt("v4",batch->getUUID().get(1));
		update.setInt("v5",batch->getUUID().get(2));
		update.setInt("v6",batch->getUUID().get(3));
		update.execute();
	} else {
		insert.setInt("v1",batch->getUUID().get(0));
		insert.setInt("v2",batch->getUUID().get(1));
		insert.setInt("v3",batch->getUUID().get(2));
		insert.setInt("v4",batch->getUUID().get(3));
		insert.setString("v5", batch->getName());
		insert.setString("v6", batch->getDescription());
		insert.execute();
	}
}

BatchRef SQLBase::getBatchByID(const UUID &id) {
	tntdb::Statement select = dbconn.prepare("SELECT name,desc FROM batches WHERE key0=:v1 AND"
	                                                                   " key1=:v2 AND"
																																		 " key2=:v3 AND"
  																																	 " key3=:v4");
	select.setInt("v1",id.get(0));
	select.setInt("v2",id.get(1));
	select.setInt("v3",id.get(2));
	select.setInt("v4",id.get(3));
	tntdb::Result res = select.select();

	if(res.size() == 0) {
		return BatchRef(static_cast<Batch *>(0));
	}
	assert(res.size() == 1);
	BatchRef batch = std::make_shared<Batch>();
	setBatchUUID(batch,id);
	std::string name;
	std::string desc;
	tntdb::Row row = *res.begin();
	row[0].get(name);
	batch->setName(name);
	row[1].get(desc);
	batch->setDescription(desc);
	return batch;
}

void SQLBase::initDB() {
	tntdb::Result res;
	try {
		res = dbconn.select("SELECT value FROM key_value WHERE key='DBversion'");
	} catch(...) {
		upgradeVersion(0);
		return;
	}

	tntdb::Row row = *res.begin();
	size_t old_version;
	row[0].get(old_version);
	upgradeVersion(old_version);
}

void SQLBase::upgradeVersion(size_t old_version) {
	if(old_version == 0) {
		dbconn.execute( "CREATE TABLE key_value(key string not null primary key,"
										"                       value int not null)");

		tntdb::Statement state = dbconn.prepare("INSERT INTO key_value VALUES (:v1, :v2)");
		state.setString("v1","DBversion").setInt("v2",CURRENT_VER).execute();

		dbconn.execute( "CREATE TABLE batches(key0 int not null,"
																			 "key1 int not null,"
																			 "key2 int not null,"
																			 "key3 int not null,"
																			 "name string not null,"
																			 "desc string,"
																			 "primary key (key0,key1,key2,key3))");
			return;
		}
	if(old_version == CURRENT_VER)
		return;
	assert(false);
}


#ifndef BATCH_H
#define BATCH_H

#include "saveable.h"
#include "uuid.h"
#include <string>
#include <memory>

class Database;

class Batch : public Saveable {
	public:
		const std::string& getName();
		const std::string& getDescription();
		void setName(const std::string& name);
		void setDescription(const std::string& desc);
		UUID getUUID() const;
	private:
		void setUUID(const UUID &id);
		UUID id;
		std::string name;
		std::string description;

		friend class DataSource;
};

typedef std::shared_ptr<Batch> BatchRef;

#endif

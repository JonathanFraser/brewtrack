#ifndef BATCH_H
#define BATCH_H

#include "uuid.h"
#include <string>
#include <memory>

class Database;

class Batch {
	public:
		std::string& getName();
		std::string& getDescription();
		void setName(const std::string& name);
		void setDescription(const std::string& desc);
		UUID getUUID() const;
	private:
		bool isSaved;
		UUID id;
		std::string name;
		std::string description;
};

typedef std::shared_ptr<Batch> BatchRef;

#endif

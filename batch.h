#ifndef BATCH_H
#define BATCH_H

#include "saveable.h"
#include "uuid.h"
#include <ctime>
#include <string>
#include <memory>

class Database;

class Batch : public Saveable {
	public:
		Batch();
		const std::string& getName() const;
		const std::string& getDescription() const;
		time_t getTimestamp() const;
		UUID getRecipeUUID() const;
		UUID getUUID() const;
		
		void setName(const std::string& name);
		void setDescription(const std::string& desc);
	private:
		void setUUID(const UUID &id);
		UUID id;
		UUID recipe_id;
		time_t timestamp;
		std::string name;
		std::string description;

		friend class DataSource;
};

typedef std::shared_ptr<Batch> BatchRef;

#endif

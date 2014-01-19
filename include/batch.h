#ifndef BATCH_H
#define BATCH_H

#include "uuid.h"
#include "recipe.h"
#include <ctime>
#include <string>
#include <memory>


class Batch {
	public:
		Batch();
		const std::string& getName() const;
		const std::string& getDescription() const;
		time_t getTimestamp() const;
		RecipeRef getRecipe() const;
		
		void setName(const std::string& name);
		void setDescription(const std::string& desc);
		UUID getUUID();

	private:
		UUID id;
		RecipeRef recipe;
		time_t timestamp;
		std::string name;
		std::string description;

};

typedef std::shared_ptr<Batch> BatchRef;

#endif

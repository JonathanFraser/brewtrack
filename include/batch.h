#ifndef BATCH_H
#define BATCH_H

#include "uuid.h"
#include "storable.h"
#include "recipe.h"
#include <string>
#include <memory>


class Batch : public Storable {
	public:
		Batch(const UUID&, DataSourceRef);
		Batch(const Recipe& recipe);
		const std::string& getName() const;
		const std::string& getDescription() const;
		
		void setName(const std::string& name);
		void setDescription(const std::string& desc);

};


#endif

#ifndef RECIPE_H
#define RECIPE_H

#include "uuid.h"
#include <string>
#include <memory>
#include <vector>

typedef std::string Quantity;

typedef struct {
	Quantity amount;
	std::string description;
} Ingredient;

typedef std::string Instruction;

typedef std::vector<Ingredient> IngredientList;
typedef std::vector<Instruction> InstructionList;

class Recipe {
	public:
		InstructionList& getInstructions();
		IngredientList& getIngredients();
	private:
		IngredientList ingredients;
		InstructionList instructions;
};

typedef std::shared_ptr<Recipe> RecipeRef;
#endif

//
// ФАЙЛ Recipe.hpp
//

#pragma once
#include <vector>
#include <memory>

#include "Step.hpp"
#include "Ingredient.hpp"
#include "EnumProcessType.hpp"

class Recipe
{
private:
	std::string m_name;											// название
	std::vector<std::shared_ptr<Ingredient>> m_ingredientList;	// список ингредиентов
	std::vector<std::unique_ptr<Step>> m_stepList;				// шаги рецепта
	int m_ingredientCapacity;									// максимум ингредиентов
	int m_stepCapacity;											// максимум шагов
	int m_cookingTime = 0;										// время для приготовления блюда

	int CalcCookingTime();

public:
	Recipe(std::string name, int ingredientCapacity, int stepCapacity);

	// геттеры
	std::shared_ptr<Ingredient> GetIngredient(int index) const;
	Step* GetStep(int index) const;
	int GetAddedIngredientCount() const;
	int GetAddedStepCount() const;
	int GetCookingTime() const;

	// добавить объект в список: возвращает true, когда успешно добавлено
	bool AddIngredient(std::string name, int count, std::string state);
	bool AddStep(std::shared_ptr<Ingredient> ingredient, ProcessType process, int time);

	void Print() const;

	~Recipe();
};
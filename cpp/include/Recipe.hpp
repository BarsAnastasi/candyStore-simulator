//
// ФАЙЛ Recipe.hpp
//

#pragma once

#include "Step.hpp"
#include "Ingredient.hpp"
#include "EnumProcessType.hpp"

class Recipe
{
private:
	std::string m_name;				// название
	Ingredient* m_ingredientList;   // список ингредиентов
	Step* m_stepList;               // шаги рецепта
	int m_ingredientCapacity;       // максимум ингредиентов
	int m_stepCapacity;             // максимум шагов
	int m_ingredientCounter;        // сколько уже добавлено
	int m_stepCounter;              // сколько уже добавлено
	int m_cookingTime = 0;			// время для приготовления блюда

	int CalcCookingTime();
public:
	Recipe(std::string name, int ingredientCapacity, int stepCapacity);

	// геттеры
	Ingredient* GetIngredient(int index) const;
	Step* GetStep(int index) const;
	int GetAddedIngredientCount() const;
	int GetAddedStepCount() const;
	int GetCookingTime() const;

	// добавить объект в список: возвращает true, когда успешно добавлено
	bool AddIngredient(std::string name, int count, std::string state);
	bool AddStep(Ingredient* ingredient, ProcessType process, int time);

	void Print() const;

	~Recipe();
};
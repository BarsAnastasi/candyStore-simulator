//
// ФАЙЛ Recipe.cpp
//

#include "Recipe.hpp"

#include <iostream>

Recipe::Recipe(std::string name, int ingredientCapacity, int stepCapacity)
	: m_name(name),
	m_ingredientCapacity(ingredientCapacity > 0 ? ingredientCapacity : 1),
	m_stepCapacity(stepCapacity > 0 ? stepCapacity : 1),
	m_ingredientCounter(0),
	m_stepCounter(0)
{
	std::cout << "Создан объект класса Recipe.\n";
	m_ingredientList = new Ingredient[m_ingredientCapacity];
	m_stepList = new Step[m_stepCapacity];
}

Recipe::~Recipe()
{
	delete[] m_ingredientList;
	delete[] m_stepList;
	
	std::cout << "Удален объект класса Recipe.\n";
}

// подсчет времени, которое нужно затратить на приготовление блюда по рецепту
int Recipe::CalcCookingTime()
{
	int t = 0;

	for (int i = 0; i < m_stepCounter; i++)
		t += m_stepList[i].GetTime();

	return t;
}

Ingredient* Recipe::GetIngredient(int index) const
{
	if (index >= 0 && index < m_ingredientCounter)
		return &m_ingredientList[index];
	std::cout << "Error! Ингредиент с таким индексом не существует.\n";
	return nullptr;
}

Step* Recipe::GetStep(int index) const
{
	if (index >= 0 && index < m_stepCounter)
		return &m_stepList[index];
	std::cout << "Error! Шаг с таким индексом не существует.\n";
	return nullptr;
}

int Recipe::GetAddedIngredientCount() const { return m_ingredientCounter; }
int Recipe::GetAddedStepCount() const { return m_stepCounter; }
int Recipe::GetCookingTime() const { return m_cookingTime; }

bool Recipe::AddIngredient(std::string name, int count, std::string state)
{
	bool statusResult = false;

	if (m_ingredientCounter < m_ingredientCapacity) {
		Ingredient ingredient(name, count);
		ingredient.ChangeState(state);
		m_ingredientList[m_ingredientCounter] = ingredient;

		m_ingredientCounter++;

		statusResult = true;
	}
	else
		std::cout << "Error! В рецепт больше нельзя добавить ингредиентов!\n";

	return statusResult;
}

bool Recipe::AddStep(Ingredient* ingredient, ProcessType process, int time)
{
	bool statusResult = false;

	if (m_stepCounter < m_stepCapacity) {
		Step step(ingredient, process, m_stepCounter + 1, time);
		m_stepList[m_stepCounter] = step;

		m_stepCounter++;
		statusResult = true;

		m_cookingTime = CalcCookingTime();
	}
	else
		std::cout << "Error! В рецепт больше нельзя добавить шаги!\n";

	return statusResult;
}


void Recipe::Print() const
{
	std::cout << "\nРецепт: \"" << m_name << "\"\n";

	std::cout << "Ингредиенты:\n";
	for (int i = 0; i < m_ingredientCounter; i++) {
		std::cout << i+1<< ". " 
			<< m_ingredientList[i].GetName() << ' '
			<< m_ingredientList[i].GetCount() << "шт.\n";
	}

	std::cout << "Шаги:\n";
	for (int i = 0; i < m_stepCounter; i++)
	{
		m_stepList[i].PrintInfo();
	}

	std::cout << "Общее время готовки: " << m_cookingTime << " сек.\n";
}
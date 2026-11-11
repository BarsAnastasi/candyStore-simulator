//
// ФАЙЛ Recipe.cpp
//

#include "Recipe.hpp"

#include <iostream>

Recipe::Recipe(std::string name, int ingredientCapacity, int stepCapacity)
	: m_name(name),
	m_ingredientCapacity(ingredientCapacity > 0 ? ingredientCapacity : 1),
	m_stepCapacity(stepCapacity > 0 ? stepCapacity : 1)
{
	std::cout << "Создан объект класса Recipe.\n";
}

Recipe::Recipe(const Recipe& other)
	: m_name(other.m_name),
	m_ingredientCapacity(other.m_ingredientCapacity),
	m_stepCapacity(other.m_stepCapacity),
	m_cookingTime(other.m_cookingTime)
{
	std::cout << "Создана копия объекта класса Recipe.\n";

	for (const auto& ing : other.m_ingredientList)
	{
		std::shared_ptr<Ingredient> newIng;
		if (ing->GetPrice() > 0)
			newIng = std::make_shared<Ingredient>(ing->GetName(), ing->GetPrice(), ing->GetCount());
		else
			newIng = std::make_shared<Ingredient>(ing->GetName(), ing->GetCount());

		newIng->ChangeState(ing->GetState());
		m_ingredientList.push_back(newIng);
	}

	for (size_t i = 0; i < other.m_stepList.size(); ++i)
	{
		if (!m_ingredientList.empty())
		{
			size_t ingIndex = i < m_ingredientList.size() ? i : 0;
			m_stepList.push_back(std::make_unique<Step>(
				m_ingredientList[ingIndex],
				other.m_stepList[i]->GetProcessType(),
				static_cast<int>(m_stepList.size()) + 1,
				other.m_stepList[i]->GetTime()));
		}
	}
}


Recipe::~Recipe()
{
	std::cout << "Удален объект класса Recipe.\n";
}

// подсчет времени, которое нужно затратить на приготовление блюда по рецепту
int Recipe::CalcCookingTime()
{
	int t = 0;

	for (const auto& step : m_stepList)
		t += step->GetTime();
	
	return t;
}

std::shared_ptr<Ingredient> Recipe::GetIngredient(int index) const
{
	if (index >= 0 && index < (int)m_ingredientList.size())
		return m_ingredientList[index];
	std::cout << "Error! Ингредиент с таким индексом не существует.\n";
	return nullptr;
}

Step* Recipe::GetStep(int index) const
{
	if (index >= 0 && index < (int)m_stepList.size())
		return m_stepList[index].get();
	std::cout << "Error! Шаг с таким индексом не существует.\n";
	return nullptr;
}

int Recipe::GetAddedIngredientCount() const { return (int)m_ingredientList.size(); }
int Recipe::GetAddedStepCount() const { return (int)m_stepList.size(); }
int Recipe::GetCookingTime() const { return m_cookingTime; }

bool Recipe::AddIngredient(std::string name, int count, std::string state)
{
	bool statusResult = false;

	if ((int)m_ingredientList.size() < m_ingredientCapacity) {
		auto ingredient = std::make_shared<Ingredient>(name, count);
		ingredient->ChangeState(state);
		m_ingredientList.push_back(ingredient);

		statusResult = true;
	}
	else
		std::cout << "Error! В рецепт больше нельзя добавить ингредиентов!\n";

	return statusResult;
}

bool Recipe::AddStep(std::shared_ptr<Ingredient> ingredient, ProcessType process, int time)
{
	bool statusResult = false;

	if ((int)m_stepList.size() < m_stepCapacity) {
		m_stepList.push_back(std::make_unique<Step>(ingredient, process, (int)m_stepList.size() + 1, time));
		m_cookingTime = CalcCookingTime();

		statusResult = true;
	}
	else
		std::cout << "Error! В рецепт больше нельзя добавить шаги!\n";

	return statusResult;
}


void Recipe::Print() const
{
	std::cout << "\nРецепт: \"" << m_name << "\"\n";

	std::cout << "Ингредиенты:\n";
	for (int i = 0; i < m_ingredientList.size(); i++) {
		std::cout << i+1<< ". " 
			<< m_ingredientList[i]->GetName() << ' '
			<< m_ingredientList[i]->GetCount() << "шт.\n";
	}

	std::cout << "Шаги:\n";
	for (const auto& step : m_stepList)
	{
		step->PrintInfo();
	}

	std::cout << "Общее время готовки: " << m_cookingTime << " сек.\n";
}
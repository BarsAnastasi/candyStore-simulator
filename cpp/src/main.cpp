// Курсовой проект "Разработка модели симулятора кондитерской"
// Автор: Барсукова А.А., студент группы ПИ-51.

#include <iostream>

// Подключение заголовочных файлов:

#include "Ingredient.hpp"
#include "EnumProcessType.hpp"
#include "Step.hpp"
#include "Recipe.hpp"

int main ()
{

	std::cout << "Курсовой проект: симулятор кондитерской. " << std::endl;

	std::cout << "\n--- Демонстрация связи между классами ---\n";

	// ограничим время существования объекта класса Recipe
	{
		std::cout << "\n--- Композиция ---\n";

		Recipe recipe("Бисквит", 3, 5);

		recipe.AddIngredient("Яйцо", 4, "сырое");
		recipe.AddIngredient("Стакан сахара", 1, "не обработан");
		recipe.AddIngredient("Стакан муки", 4, "не обработан");

		recipe.AddStep(recipe.GetIngredient(0), ProcessType::eWash, 10);
		recipe.AddStep(recipe.GetIngredient(0), ProcessType::eBeat, 60);
		recipe.AddStep(recipe.GetIngredient(1), ProcessType::eAdd, 10);
		recipe.AddStep(recipe.GetIngredient(2), ProcessType::eAdd, 10);
		recipe.AddStep(recipe.GetIngredient(1), ProcessType::eBake, 15 * 60);

		recipe.Print();
	}

	std::cout << "\n--- Агрегация ---\n";

	Ingredient eggs("Яйцо", 100, 10);
	
	eggs.PrintInfo();

	Step step1(&eggs, ProcessType::eWash, 1, 15);

	step1.PrintInfo();

	return 0; 

}
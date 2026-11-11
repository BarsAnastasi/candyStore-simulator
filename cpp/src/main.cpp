// Курсовой проект "Разработка модели симулятора кондитерской"
// Автор: Барсукова А.А., студент группы ПИ-51.

#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "Ingredient.hpp"
#include "EnumProcessType.hpp"
#include "Step.hpp"
#include "Recipe.hpp"
#include "BaseDish.hpp"
#include "Dessert.hpp"
#include "Drink.hpp"

// Обработка строк: find и substr
std::string ExtractDishTitle(std::string_view description)
{
	std::string text(description);
	std::size_t firstQuote = text.find('\"');
	if (firstQuote != std::string::npos)
	{
		std::size_t secondQuote = text.find('\"', firstQuote + 1);
		if (secondQuote != std::string::npos)
		{
			return text.substr(firstQuote + 1, secondQuote - firstQuote - 1);
		}
	}
	return "Не найдено";
}

int main()
{
	std::cout << "=== 1. Конструкторы, деструкторы и передача *this ===\n";
	{
		auto cakeRecipe = std::make_shared<Recipe>("Медовик", 2, 1);
		cakeRecipe->AddIngredient("Мёд", 2, "жидкий");
		cakeRecipe->AddStep(cakeRecipe->GetIngredient(0), ProcessType::eBake, 600);

		Dessert honeyCake("Торт Медовик", cakeRecipe, 160, true);
		OrderBoard board;
		honeyCake.SendToBoard(board);
	}

	std::cout << "\n=== 2. Поверхностная и глубокая копия ===\n";
	{
		auto milkShakeRecipe = std::make_shared<Recipe>("Молочный коктейль базовый", 2, 1);
		milkShakeRecipe->AddIngredient("Молоко", 1, "холодное");
		milkShakeRecipe->AddStep(milkShakeRecipe->GetIngredient(0), ProcessType::eBeat, 30);

		// Поверхностное разделение: оба напитка ссылаются на один std::shared_ptr<Recipe>
		std::unique_ptr<BaseDish> shake1 = std::make_unique<Drink>("Клубничный коктейль", milkShakeRecipe, 350, false);
		std::unique_ptr<BaseDish> shake2 = std::make_unique<Drink>("Ванильный коктейль", milkShakeRecipe, 350, false);

		// Глубокая копия через Clone()
		std::unique_ptr<BaseDish> deepCopyShake = shake1->Clone();

		// Изменяем рецепт через shake1
		shake1->ChangeRecipeName("Молочный коктейль (НОВЫЙ РЕЦЕПТ)");

		std::cout << "Оригинал:       ";
		shake1->PrintInfo();
		std::cout << "Общий рецепт:   ";
		shake2->PrintInfo();
		std::cout << "Глубокая копия: ";
		deepCopyShake->PrintInfo();
	}

	std::cout << "\n=== 3. Работа со строками (конкатенация, find, substr, сравнение) ===\n";
	{
		auto teaRecipe = std::make_shared<Recipe>("Облепиховый чай", 1, 1);
		Drink tea("Чай с облепихой", teaRecipe, 400, true);

		std::string desc = tea.Describe();
		std::string title = ExtractDishTitle(desc);
		std::string fullMessage = "Заказ: " + desc + " [ОПЛАЧЕНО]";

		std::cout << fullMessage << "\n";
		if (title == "Чай с облепихой")
		{
			std::cout << "Название извлечено верно: " << title << "\n";
		}
	}

	std::cout << "\n=== 4. Массив std::unique_ptr<BaseDish> и статический счётчик ===\n";
	{
		std::vector<std::unique_ptr<BaseDish>> menu;

		auto r1 = std::make_shared<Recipe>("Панна-котта", 1, 1);
		auto r2 = std::make_shared<Recipe>("Капучино", 1, 1);

		menu.push_back(std::make_unique<Dessert>("Панна-котта ягодная", r1, 150, false));
		menu.push_back(std::make_unique<Drink>("Капучино", r2, 250, true));

		std::cout << "Активных блюд в системе: " << BaseDish::GetDishCount() << "\n";

		for (const auto& item : menu)
		{
			item->PrintInfo();
		}
	}

	std::cout << "\nБлюд после очистки памяти: " << BaseDish::GetDishCount() << "\n";
	return 0;
}

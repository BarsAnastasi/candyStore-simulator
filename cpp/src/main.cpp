// Курсовой проект "Разработка модели симулятора кондитерской"
// Автор: Барсукова А.А., студент группы ПИ-51.

#include <iostream>
#include <memory>

// Подключение заголовочных файлов:

#include "Ingredient.hpp"
#include "EnumProcessType.hpp"
#include "Step.hpp"
#include "Recipe.hpp"

int main()
{
    // Демонстрация 1: shared_ptr и use_count
    std::cout << "\n--- Демонстрация shared_ptr ---\n";
    auto eggs = std::make_shared<Ingredient>("Яйцо", 100, 10);
    std::cout << "use_count после создания: " << eggs.use_count() << "\n"; // 1

    std::shared_ptr<Ingredient> eggsCopy = eggs; // копия
    std::cout << "use_count после копирования: " << eggs.use_count() << "\n"; // 2

    eggsCopy.reset(); // отпускаем владение
    std::cout << "use_count после reset: " << eggs.use_count() << "\n"; // 1

    // Демонстрация 2: weak_ptr в действии
    std::cout << "\n--- Демонстрация weak_ptr ---\n";
    std::weak_ptr<Ingredient> watcher = eggs;
    {
        auto step1 = std::make_shared<Step>(eggs, ProcessType::eWash, 1, 15);
        std::cout << "weak_ptr жив, пока eggs жив. lock() работает:\n";
        step1->PrintInfo();
    }

    // Композиция и агрегация в Recipe
    std::cout << "\n--- Композиция и агрегация ---\n";
    {
        Recipe recipe("Бисквит", 3, 5);
        recipe.AddIngredient("Яйцо", 4, "сырое");
        recipe.AddIngredient("Стакан сахара", 1, "не обработан");
        recipe.AddIngredient("Стакан муки", 4, "не обработан");
        recipe.AddIngredient("Ингредиент", 1, "-"); // Error!

        recipe.AddStep(recipe.GetIngredient(0), ProcessType::eWash, 10);
        recipe.AddStep(recipe.GetIngredient(0), ProcessType::eBeat, 60);
        recipe.AddStep(recipe.GetIngredient(1), ProcessType::eAdd, 10);
        recipe.AddStep(recipe.GetIngredient(2), ProcessType::eAdd, 10);
        recipe.AddStep(recipe.GetIngredient(1), ProcessType::eBake, 900);

        recipe.Print();
    } // здесь всё внутри recipe удалится

    // Демонстрация unique_ptr: передача владения
    std::cout << "\n--- Демонстрация unique_ptr ---\n";
    auto uniqueStep = std::make_unique<Step>(eggs, ProcessType::eCut, 2, 20);
    std::cout << "unique_ptr жив, шаг создан.\n";
    uniqueStep->PrintInfo();
    // uniqueStep умрёт сам при выходе из main

    return 0;
}
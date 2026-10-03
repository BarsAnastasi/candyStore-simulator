// Курсовой проект "Разработка модели симулятора кондитерской"
// Автор: Барсукова А.А., студент группы ПИ-51.

#include <iostream>

// Подключение заголовочных файлов:

#include "Ingredient.hpp"
#include "EnumProcessType.hpp"
#include "Step.hpp"

int main ()
{

	std::cout << "Курсовой проект: симулятор кондитерской. " << std::endl;

	Ingredient eggs("Яйцо", 100, 10);
	
	eggs.PrintInfo();

	Step step1(&eggs, ProcessType::Wash, 1, 15);
	Step step2(&eggs, ProcessType::Beat, 2, 60);

	step1.PrintInfo();
	step2.PrintInfo();

	return 0; 

}
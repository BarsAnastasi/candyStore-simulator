
// Реализация класса Step

#include <iostream>
#include "Step.hpp"
#include "Ingredient.hpp"
#include "EnumProcessType.hpp"


Step::Step(Ingredient* ingredient, ProcessType process, int stepNum, int time)
{
	std::cout << "Создан объект класса Step.\n";

	this->ingredient = ingredient;
	this->process = process;

	if(stepNum > 0)
		this->stepNum = stepNum;
	else
		std::cout << "Error! Порядковый номер шага должен быть больше 0.\n";

	if (time > 0)
		this->time = time;
	else
		std::cout << "Error! Время выполнения шага должно быть больше 0.\n";
}

// геттеры
int Step::GetTime() const { return time; }
ProcessType Step::GetProcessType() const { return process; }
std::string Step::GetIngredientName() const { return ingredient->GetName(); }
std::string Step::GetProcessString() const
{
	std::string ProcessString;
	switch (process)
	{
	case ProcessType::Wash:ProcessString = "помыть"; break;
	case ProcessType::Cut: ProcessString = "порезать"; break;
	case ProcessType::Beat:ProcessString = "взбить"; break;
	case ProcessType::Add: ProcessString = "добавить"; break;
	case ProcessType::Bake: ProcessString = "запечь"; break;
	case ProcessType::Fry: ProcessString = "пожарить"; break;
	case ProcessType::Cook: ProcessString = "варить"; break;
	case ProcessType::Freeze: ProcessString = "заморозить"; break;
	default:
		ProcessString = "-";
		std::cout << "Error! Тип обработки для шага " << stepNum << " передан неверно!\n";
	}

	return ProcessString;
}


void Step::PrintInfo() const
{
	std::cout << stepNum << ". " << ingredient->GetName() << ' ' << GetProcessString() << ' ' << time << " сек.\n";
}


Step::~Step()
{
	std::cout << "Удален объект класса Step.\n";
}
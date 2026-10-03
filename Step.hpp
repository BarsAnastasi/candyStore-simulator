//
// ФАЙЛ Step.hpp
//

#pragma once

#include "Ingredient.hpp"
#include "EnumProcessType.hpp"

class Step
{
private:
	Ingredient* m_ingredient;   // ссылка на ингредиент рецепта
	ProcessType m_process;		// тип обработки
	int m_stepNum;				// номер шага
	int m_time;					// время выполнения

public:
	Step();
	Step(Ingredient* ingredient, ProcessType process, int stepNum, int time);

	// геттеры
	int GetTime() const;
	ProcessType GetProcessType() const;
	std::string GetProcessString() const;

	void PrintInfo() const;

	~Step();
};
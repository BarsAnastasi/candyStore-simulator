//
// ФАЙЛ Step.hpp
//

#pragma once
#include <memory>

#include "Ingredient.hpp"
#include "EnumProcessType.hpp"

class Step
{
private:
	std::weak_ptr<Ingredient> m_ingredient;
	ProcessType m_process;		// тип обработки
	int m_stepNum;				// номер шага
	int m_time;					// время выполнения

public:
	Step();
	Step(std::shared_ptr<Ingredient> ingredient, ProcessType process, int stepNum, int time);

	// геттеры
	int GetTime() const;
	ProcessType GetProcessType() const;
	std::string GetProcessString() const;

	void PrintInfo() const;

	~Step();
};
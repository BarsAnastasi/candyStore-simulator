//
// ФАЙЛ Step.cpp
//

#include "Step.hpp"
#include "Ingredient.hpp"
#include "EnumProcessType.hpp"

#include <iostream>

Step::Step()
	: m_ingredient(nullptr), m_process(ProcessType::eCook), m_stepNum(1), m_time(1)
{
	std::cout << "Создан объект класса Step c конструктором без параметров.\n";
}

Step::Step(Ingredient* ingredient, ProcessType process, int stepNum, int time)
	: m_ingredient(ingredient), m_process(process)
{
	std::cout << "Создан объект класса Step.\n";

	if(m_stepNum > 0)
		m_stepNum = stepNum;
	else
		std::cout << "Error! Порядковый номер шага должен быть больше 0.\n";

	if (m_time > 0)
		m_time = time;
	else
		std::cout << "Error! Время выполнения шага должно быть больше 0.\n";
}

Step::~Step()
{
	std::cout << "Удален объект класса Step.\n";
}

int Step::GetTime() const { return m_time; }
ProcessType Step::GetProcessType() const { return m_process; }

std::string Step::GetProcessString() const
{
	switch (m_process) {
	case ProcessType::eWash:   return "помыть";
	case ProcessType::eCut:    return "порезать";
	case ProcessType::eBeat:   return "взбить";
	case ProcessType::eAdd:    return "добавить";
	case ProcessType::eBake:   return "запечь";
	case ProcessType::eFry:    return "пожарить";
	case ProcessType::eCook:   return "варить";
	case ProcessType::eFreeze: return "заморозить";
	}
	return "ничего";
}


void Step::PrintInfo() const
{
	std::cout << m_stepNum << ". " 
			  << m_ingredient->GetName() << ' ' 
		<< m_ingredient->GetCount() << " шт. в состоянии " << m_ingredient->GetState() 
		<< ", " << GetProcessString() << ' ' 
		<< m_time << " сек.\n";
}
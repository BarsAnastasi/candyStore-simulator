#pragma once

// Объявление класса Step

#include "Ingredient.hpp"
#include "EnumProcessType.hpp"

class Step
{
private:
	Ingredient* ingredient;
	ProcessType process;
	int stepNum,
		time;
	
	

public:
	Step(Ingredient* ingredient, ProcessType process, int stepNum, int time);

	// геттеры
	int GetTime() const;
	ProcessType GetProcessType() const;
	std::string GetIngredientName() const;
	std::string GetProcessString() const;

	void PrintInfo() const;

	~Step();
};
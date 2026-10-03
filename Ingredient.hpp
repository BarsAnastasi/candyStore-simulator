//
// ФАЙЛ Ingredient.hpp
//

#pragma once

#include <iostream>

class Ingredient
{
private:
	std::string m_name,		// название
		m_state;			// состояние
	int m_price,			// цена/шт.
		m_count;			// количество

public:
	Ingredient();
	Ingredient(std::string name, int price, int count);
	Ingredient(std::string name, int count);

	// геттеры
	std::string GetName() const;
	std::string GetState() const;
	int GetPrice() const;
	int GetCount() const;

	// управление состоянием
	void ChangeState(std::string state);
	void SetPrice(int price);

	// изменение количества 
	void SetCount(int count);
	int RaiseCount(int delta = 1);	// докупить определенное количество единиц ингредиента 
	int ReduceCount(int delta = 1);	// уничтожить определенное количество единиц ингредиента

	void PrintInfo() const;

	~Ingredient();
};
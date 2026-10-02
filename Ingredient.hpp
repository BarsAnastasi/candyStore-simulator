
// Объявление класса Ingredient

#pragma once

#include <string>

class Ingredient
{
private:
	std::string name,	// название ингредиента
		state;			// состояние ингредиента
	int price,			// цена за штуку
		count;			// количество

	

public:
	Ingredient(std::string name, int price, int count);

	// getters:

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
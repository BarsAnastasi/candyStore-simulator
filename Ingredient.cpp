
// Реализация класса Ingredient

#include <iostream>
#include "Ingredient.hpp"

Ingredient::Ingredient(std::string name, int price, int count)
{
	std::cout << "Создан объект класса Ingredient.\n";
	this->name = name;
	this->state = "не обработан";
	SetPrice(price);
	SetCount(count);
}

Ingredient::~Ingredient()
{
	std::cout << "Объект класса Ingredient удален.\n";
}

// getters:

std::string Ingredient::GetName() const { return this->name; }
std::string Ingredient::GetState() const { return this->state; }
int Ingredient::GetPrice() const { return this->price; }
int Ingredient::GetCount() const { return this->count; }


void Ingredient::SetCount(int count)
{
	if (count >= 0)
		this->count = count;
	else
		std::cout << "Error! Количество ингредиентов не может быть отрицательным.\n";
}

int Ingredient::RaiseCount(int delta)
{
	if (delta >= 0)
		count += delta;
	else
		std::cout << "Error! Нельзя добавить отрицательное количество единиц ингредиента.\n";

	return count;
}

int Ingredient::ReduceCount(int delta)
{
	if (count - delta >= 0)
		count -= delta;
	else
		std::cout << "Error! Ингредиентов не хватает.\n";

	return count;
}

void Ingredient::SetPrice(int price)
{
	if (price > 0)
		this->price = price;
	else
		std::cout << "Error! Цена должна быть больше 0.\n";
}

void Ingredient::ChangeState(std::string state)
{
	this->state = state;
}

void Ingredient::PrintInfo() const
{
	std::cout << "\nИнгредиент " << name << "\nСостояние: " << state << "\nКоличество: " << count << "\nЦена за штуку: " << price << "\n\n";
}
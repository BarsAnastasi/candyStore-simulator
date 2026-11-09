//
// ФАЙЛ Ingredient.cpp
//

#include "Ingredient.hpp"

#include <iostream>

Ingredient::Ingredient()
	: m_name("-"), m_state("не задан"), m_price(0), m_count(0)
{
	std::cout << "Создан объект класса Ingredient с конструктором без параметров.\n";
}

Ingredient::Ingredient(std::string name, int price, int count)
	: m_name(name), m_state("не обработан"), m_price(0), m_count(0)
{
	std::cout << "Создан объект класса Ingredient.\n";
	SetPrice(price);
	SetCount(count);
}

Ingredient::Ingredient(std::string name, int count)
	: m_name(name), m_state("не обработан"), m_price(0), m_count(0)
{
	std::cout << "Создан объект класса Ingredient без указания цены.\n";
	SetCount(count);
}

Ingredient::~Ingredient()
{
	std::cout << "Объект класса Ingredient удален.\n";
}

std::string Ingredient::GetName() const { return m_name; }
std::string Ingredient::GetState() const { return m_state; }
int Ingredient::GetPrice() const { return m_price; }
int Ingredient::GetCount() const { return m_count; }

void Ingredient::SetCount(int count)
{
	if (count >= 0)
		m_count = count;
	else
		std::cout << "Error! Количество ингредиентов не может быть отрицательным.\n";
}

int Ingredient::RaiseCount(int delta)
{
	if (delta >= 0)
		m_count += delta;
	else
		std::cout << "Error! Нельзя добавить отрицательное количество.\n";
	return m_count;
}

int Ingredient::ReduceCount(int delta)
{
	if (m_count - delta >= 0)
		m_count -= delta;
	else
		std::cout << "Error! Ингредиентов не хватает.\n";
	return m_count;
}

void Ingredient::SetPrice(int price)
{
	if (price > 0)
		m_price = price;
	else
		std::cout << "Error! Цена должна быть больше 0.\n";
}

void Ingredient::ChangeState(std::string state)
{
	m_state = state;
}

void Ingredient::PrintInfo() const
{
	std::cout << "Ингредиент: " << m_name << "\n"
		<< "  Состояние: " << m_state << "\n"
		<< "  Количество: " << m_count << "\n"
		<< "  Цена: " << m_price << "\n";
}
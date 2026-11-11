//
// ФАЙЛ Dessert.cpp
//

#include "Dessert.hpp"

Dessert::Dessert()
	: BaseDish(), m_weightGrams(100), m_needsBaking(false)
{
	std::cout << "Создан объект Dessert (по умолчанию).\n";
}

Dessert::Dessert(std::string_view name, std::shared_ptr<Recipe> recipe, int weightGrams, bool needsBaking)
	: BaseDish(name, std::move(recipe)),
	m_weightGrams(weightGrams > 0 ? weightGrams : 100),
	m_needsBaking(needsBaking)
{
	std::cout << "Создан объект Dessert (" << m_weightGrams << " г).\n";
}

Dessert::~Dessert()
{
	std::cout << "Удален объект Dessert.\n";
}

std::string Dessert::GetServeWay() const
{
	return m_needsBaking ? "на десертной тарелке с вилкой" : "в креманке с ложечкой";
}

std::string Dessert::Describe() const
{
	return BaseDish::Describe() + " | Десерт, вес: " + std::to_string(m_weightGrams) + " г.";
}

std::unique_ptr<BaseDish> Dessert::Clone() const
{
	return std::make_unique<Dessert>(*this);
}

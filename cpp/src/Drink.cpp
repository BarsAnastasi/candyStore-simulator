//
// ФАЙЛ Drink.cpp
//

#include "Drink.hpp"

Drink::Drink()
	: BaseDish(), m_volumeMl(250), m_isHot(true)
{
	std::cout << "Создан объект Drink (по умолчанию).\n";
}

Drink::Drink(std::string_view name, std::shared_ptr<Recipe> recipe, int volumeMl, bool isHot)
	: BaseDish(name, std::move(recipe)),
	m_volumeMl(volumeMl > 0 ? volumeMl : 250),
	m_isHot(isHot)
{
	std::cout << "Создан объект Drink (" << m_volumeMl << " мл).\n";
}

Drink::~Drink()
{
	std::cout << "Удален объект Drink.\n";
}

std::string Drink::GetServeWay() const
{
	return m_isHot ? "в керамической кружке" : "в высоком стакане с трубочкой";
}

std::string Drink::Describe() const
{
	std::string temp = m_isHot ? "Горячий" : "Холодный";
	return temp + " напиток (" + std::to_string(m_volumeMl) + " мл, " + GetServeWay() + ") -> " + FormatHeader();
}

std::unique_ptr<BaseDish> Drink::Clone() const
{
	return std::make_unique<Drink>(*this);
}

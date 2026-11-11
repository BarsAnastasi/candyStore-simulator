//
// ФАЙЛ BaseDish.cpp
//

#include "BaseDish.hpp"

void OrderBoard::AnnounceDish(const BaseDish& dish) const
{
	std::cout << "[Табло заказов] На выдачу: " << dish.Describe() << "\n";
}

BaseDish::BaseDish()
	: m_name("Блюдо без названия"), m_recipe(nullptr)
{
	++s_dishCount;
	std::cout << "Создан объект BaseDish (по умолчанию). Всего блюд: " << s_dishCount << ".\n";
}

BaseDish::BaseDish(std::string_view name, std::shared_ptr<Recipe> recipe)
	: m_name(name), m_recipe(std::move(recipe))
{
	++s_dishCount;
	std::cout << "Создан объект BaseDish: \"" << m_name << "\". Всего блюд: " << s_dishCount << ".\n";
}

BaseDish::BaseDish(const BaseDish& other)
	: m_name(other.m_name),
	m_recipe(other.m_recipe ? std::make_shared<Recipe>(*other.m_recipe) : nullptr)
{
	++s_dishCount;
	std::cout << "Создана копия BaseDish: \"" << m_name << "\". Всего блюд: " << s_dishCount << ".\n";
}

BaseDish& BaseDish::operator=(const BaseDish& other)
{
	if (this == &other)
	{
		return *this;
	}

	m_name = other.m_name;
	m_recipe = other.m_recipe ? std::make_shared<Recipe>(*other.m_recipe) : nullptr;

	return *this;
}

BaseDish::~BaseDish()
{
	--s_dishCount;
	std::cout << "Удален объект BaseDish: \"" << m_name << "\". Осталось блюд: " << s_dishCount << ".\n";
}

std::string BaseDish::FormatHeader() const
{
	std::string recipeName = m_recipe ? m_recipe->GetName() : "без рецепта";
	int cookTime = m_recipe ? m_recipe->GetCookingTime() : 0;
	return "\"" + m_name + "\" [рецепт: " + recipeName + ", время: " + std::to_string(cookTime) + " сек.]";
}

std::string BaseDish::Describe() const
{
	return FormatHeader() + ", подача: " + GetServeWay();
}

void BaseDish::PrintInfo() const
{
	std::cout << Describe() << "\n";
}

void BaseDish::ChangeRecipeName(std::string_view newName)
{
	if (m_recipe)
	{
		m_recipe->SetName(std::string(newName));
	}
}

void BaseDish::SendToBoard(const OrderBoard& board) const
{
	board.AnnounceDish(*this);
}

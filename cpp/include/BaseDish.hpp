//
// ФАЙЛ BaseDish.hpp
//

#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include "Recipe.hpp"

class BaseDish;

// Вспомогательный класс для демонстрации передачи *this другому объекту
class OrderBoard
{
public:
	void AnnounceDish(const BaseDish& dish) const;
};

class BaseDish
{
private:
	inline static int s_dishCount = 0;

	std::string m_name;
	std::shared_ptr<Recipe> m_recipe;

protected:
	std::string FormatHeader() const;

	BaseDish(const BaseDish& other);
	BaseDish& operator=(const BaseDish& other);

	BaseDish(BaseDish&& other) noexcept = default;
	BaseDish& operator=(BaseDish&& other) noexcept = default;

public:
	BaseDish();
	BaseDish(std::string_view name, std::shared_ptr<Recipe> recipe);
	virtual ~BaseDish();

	static int GetDishCount() { return s_dishCount; }

	virtual std::string GetServeWay() const = 0;
	virtual std::unique_ptr<BaseDish> Clone() const = 0;

	virtual std::string Describe() const;
	void PrintInfo() const;

	std::string_view GetName() const { return m_name; }
	void ChangeRecipeName(std::string_view newName);

	// Передача *this другому объекту
	void SendToBoard(const OrderBoard& board) const;
};

//
// ФАЙЛ Dessert.hpp
//

#pragma once

#include "BaseDish.hpp"

class Dessert : public BaseDish
{
private:
	int m_weightGrams;
	bool m_needsBaking;

public:
	Dessert();
	Dessert(std::string_view name, std::shared_ptr<Recipe> recipe, int weightGrams, bool needsBaking);

	Dessert(const Dessert& other) = default;
	Dessert& operator=(const Dessert& other) = default;
	Dessert(Dessert&& other) noexcept = default;
	Dessert& operator=(Dessert&& other) noexcept = default;
	~Dessert() override;

	std::string GetServeWay() const override;
	std::string Describe() const override;
	std::unique_ptr<BaseDish> Clone() const override;
};

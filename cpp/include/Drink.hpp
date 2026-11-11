//
// ФАЙЛ Drink.hpp
//

#pragma once

#include "BaseDish.hpp"

class Drink final : public BaseDish
{
private:
	int m_volumeMl;
	bool m_isHot;

public:
	Drink();
	Drink(std::string_view name, std::shared_ptr<Recipe> recipe, int volumeMl, bool isHot);

	Drink(const Drink& other) = default;
	Drink& operator=(const Drink& other) = default;
	Drink(Drink&& other) noexcept = default;
	Drink& operator=(Drink&& other) noexcept = default;
	~Drink() override;

	std::string GetServeWay() const override;
	std::string Describe() const override;
	std::unique_ptr<BaseDish> Clone() const override;
};

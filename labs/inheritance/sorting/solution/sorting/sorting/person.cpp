#include "person.h"

std::string Person::getFirstName() const
{
	return this->firstName;
}

std::string Person::getLastName() const
{
	return this->lastName;
}

double Person::getWeightInKg() const
{
	return this->weightInKg;
}

unsigned Person::getHeightInCm() const
{
	return this->heightInCm;
}

std::ostream& operator <<(std::ostream& out, const Person& person)
{
	return out << person.getFirstName() << " " << person.getLastName() << " (weight = " << person.getWeightInKg() << "kg, height = " << person.getHeightInCm() << "cm)";
}

comparison_result Person::Comparison::ByFirstName::compare(const Person& p1, const Person& p2) const
{
	// Create local constant references
	// Allows for copy paste (better solutions are possible using templates)
	const auto& x = p1.getFirstName();
	const auto& y = p2.getFirstName();

	if (x < y) return comparison_result::LESS;
	else if (x > y) return comparison_result::GREATER;
	else return comparison_result::EQUAL;
}

comparison_result Person::Comparison::ByLastName::compare(const Person& p1, const Person& p2) const
{
	const auto& x = p1.getLastName();
	const auto& y = p2.getLastName();

	if (x < y) return comparison_result::LESS;
	else if (x > y) return comparison_result::GREATER;
	else return comparison_result::EQUAL;
}

comparison_result Person::Comparison::ByWeight::compare(const Person& p1, const Person& p2) const
{
	const auto& x = p1.getWeightInKg();
	const auto& y = p2.getWeightInKg();

	if (x < y) return comparison_result::LESS;
	else if (x > y) return comparison_result::GREATER;
	else return comparison_result::EQUAL;
}

comparison_result Person::Comparison::ByHeight::compare(const Person& p1, const Person& p2) const
{
	const auto& x = p1.getHeightInCm();
	const auto& y = p2.getHeightInCm();

	if (x < y) return comparison_result::LESS;
	else if (x > y) return comparison_result::GREATER;
	else return comparison_result::EQUAL;
}

comparison_result ComparisonInverter::compare(const Person& p1, const Person& p2) const
{
	return this->comparer->compare(p2, p1);
}

comparison_result LexicoComparer::compare(const Person& p1, const Person& p2) const
{
	auto result = c1->compare(p1, p2);

	if (result != comparison_result::EQUAL)
	{
		return result;
	}
	else
	{
		return c2->compare(p1, p2);
	}
}

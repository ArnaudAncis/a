#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <memory>
#include <string>

enum comparison_result
{
	LESS, GREATER, EQUAL
};

class Person;

struct PersonComparer
{
	virtual ~PersonComparer() { }

	comparison_result virtual compare(const Person&, const Person&) const = 0;
};

class Person
{
private:
	std::string firstName, lastName;
	double weightInKg;
	unsigned heightInCm;

public:
	Person(std::string firstName, std::string lastName, double weightInKg, unsigned heightInCm)
		: firstName(firstName), lastName(lastName), weightInKg(weightInKg), heightInCm(heightInCm) { }

	std::string getFirstName() const;
	std::string getLastName() const;
	double getWeightInKg() const;
	unsigned getHeightInCm() const;

	struct Comparison
	{
		struct ByFirstName : public PersonComparer
		{
			comparison_result compare(const Person&, const Person&) const override;
		};

		struct ByLastName : public PersonComparer
		{
			comparison_result compare(const Person&, const Person&) const override;
		};

		struct ByWeight : public PersonComparer
		{
			comparison_result compare(const Person&, const Person&) const override;
		};

		struct ByHeight : public PersonComparer
		{
			comparison_result compare(const Person&, const Person&) const override;
		};
	};
};

std::ostream& operator <<(std::ostream&, const Person&);

class ComparisonInverter : public PersonComparer
{
	std::shared_ptr<const PersonComparer> comparer;

public:
	ComparisonInverter(std::shared_ptr<const PersonComparer> c) : comparer(c) { }

	comparison_result compare(const Person&, const Person&) const override;
};

class LexicoComparer : public PersonComparer
{
	std::shared_ptr<const PersonComparer> c1, c2;

public:
	LexicoComparer(std::shared_ptr<const PersonComparer> c1, std::shared_ptr<const PersonComparer> c2 )
		: c1(c1), c2(c2) { }

	comparison_result compare(const Person&, const Person&) const override;
};

#endif
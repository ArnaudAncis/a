#include "person.h"
#include <vector>

void sort(std::vector<std::shared_ptr<Person>>& people, const PersonComparer& comparer)
{
	bool sorted = false;

	while (!sorted)
	{
		sorted = true;

		for (unsigned i = 1; i < people.size(); ++i)
		{
			auto p1 = people[i - 1];
			auto p2 = people[i];

			if (comparer.compare(*p1, *p2) == comparison_result::GREATER)
			{
				people[i - 1] = p2;
				people[i] = p1;

				sorted = false;
			}
		}
	}
}

int main()
{
	std::vector<std::shared_ptr<Person>> people = {
		std::make_shared<Person>("Jan", "Janssens", 60, 165),
		std::make_shared<Person>("Piet", "Janssens", 90, 180),
		std::make_shared<Person>("Jan", "Janssens", 120, 150),
		std::make_shared<Person>("Jyrg", "Snoders", 75, 180),
		std::make_shared<Person>("Jan", "Janssens", 150, 210),
		std::make_shared<Person>("An", "Janssens", 55, 165) };

	auto lastname = std::make_shared<Person::Comparison::ByLastName>();
	auto firstname = std::make_shared<Person::Comparison::ByFirstName>();
	auto lastfirst = std::make_shared<LexicoComparer>(lastname, firstname);
	auto ascweight = std::make_shared<Person::Comparison::ByWeight>();
	auto descweight = std::make_shared<ComparisonInverter>(ascweight);
	auto comparer = LexicoComparer(lastfirst, descweight);

	sort(people, comparer);

	for (const auto& p : people)
	{
		std::cout << *p << std::endl;
	}
}
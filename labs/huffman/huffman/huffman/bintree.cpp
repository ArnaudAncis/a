#include "bintree.h"
#include <list>
#include <limits>
#include <assert.h>

std::shared_ptr<bintree> extract_lightest(std::list<std::shared_ptr<bintree>>& nodes)
{
	auto it = nodes.begin();
	auto best = it;

	while (it != nodes.end())
	{
		if ((*it)->weight() < (*best)->weight())
		{
			best = it;
		}
		
		++it;
	}

	auto result = *best;
	nodes.erase(best);

	return result;
}

std::shared_ptr<bintree> build_tree(const frequency_map& frequencies)
{
    std::list<std::shared_ptr<bintree>> nodes;

	// Build list of leaves
	nodes.push_back(std::make_shared<eof_leaf>());

	for (uint16_t i = std::numeric_limits<uint8_t>::min(); i <= std::numeric_limits<uint8_t>::max(); ++i)
	{
		if (frequencies[uint8_t(i)] > 0)
		{
			nodes.push_back(std::make_shared<datum_leaf>(frequencies[uint8_t(i)], uint8_t(i)));
		}
	}

	assert(!nodes.empty());

	// Build tree
	while (nodes.size() > 1)
	{
		auto left = extract_lightest(nodes);
		auto right = extract_lightest(nodes);

		nodes.push_back(std::make_shared<branch>(left, right));
	}

	// Return root
	return nodes.front();
}
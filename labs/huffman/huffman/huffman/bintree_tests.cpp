/*

TESTS

*/

#include "Catch.h"
#include "bintree.h"

std::shared_ptr<leaf> get_leaf(std::shared_ptr<bintree> root, std::string code)
{
	auto current = root;

	for (char c : code)
	{
		auto b = std::dynamic_pointer_cast<branch>(current);

		REQUIRE(b != nullptr);

		if (c == '0')
		{
			current = b->left();
		}
		else if (c == '1')
		{
			current = b->right();
		}
		else
		{
			abort();
		}
	}

	auto lf = std::dynamic_pointer_cast<leaf>(current);

	REQUIRE(lf != nullptr);

	return lf;
}

void require_datum_path(std::shared_ptr<bintree> root, std::string code, uint8_t datum, unsigned weight)
{
	auto lf = std::dynamic_pointer_cast<datum_leaf>(get_leaf(root, code));

	REQUIRE(lf != nullptr);	
	REQUIRE(lf->datum() == datum);
}

void require_eof_path(std::shared_ptr<bintree> root, std::string code)
{
	auto lf = std::dynamic_pointer_cast<eof_leaf>(get_leaf(root, code));

	REQUIRE(lf != nullptr);
}

TEST_CASE("Creating tree for { }", "[complex]")
{
	frequency_map frequencies;
	std::shared_ptr<bintree> root = build_tree(frequencies);

	require_eof_path(root, "");
}

TEST_CASE("Creating tree for { A => 1 }", "[complex]")
{
	frequency_map frequencies;
	frequencies['A'] = 1;

	std::shared_ptr<bintree> root = build_tree(frequencies);

	require_eof_path(root, "0");
	require_datum_path(root, "1", 'A', 1);
}

TEST_CASE("Creating tree for { A => 2 }", "[complex]")
{
	frequency_map frequencies;
	frequencies['A'] = 2;

	std::shared_ptr<bintree> root = build_tree(frequencies);

	require_eof_path(root, "0");
	require_datum_path(root, "1", 'A', 2);
}

TEST_CASE("Creating tree for { B => 1 }", "[complex]")
{
	frequency_map frequencies;
	frequencies['B'] = 1;

	std::shared_ptr<bintree> root = build_tree(frequencies);

	require_eof_path(root, "0");
	require_datum_path(root, "1", 'B', 1);
}

TEST_CASE("Creating tree for { A => 1, B => 2 }", "[complex]")
{
	frequency_map frequencies;
	frequencies['A'] = 1;
	frequencies['B'] = 2;

	std::shared_ptr<bintree> root = build_tree(frequencies);

	require_eof_path(root, "00");
	require_datum_path(root, "01", 'A', 1);
	require_datum_path(root, "1", 'B', 2);
}

TEST_CASE("Creating tree for { A => 1, B => 2, C => 4 }", "[complex]")
{
	frequency_map frequencies;
	frequencies['A'] = 1;
	frequencies['B'] = 2;
	frequencies['C'] = 4;

	std::shared_ptr<bintree> root = build_tree(frequencies);

	require_eof_path(root, "000");
	require_datum_path(root, "001", 'A', 1);
	require_datum_path(root, "01", 'B', 2);
	require_datum_path(root, "1", 'C', 4);
}

TEST_CASE("Creating tree for { A => 4, B => 2, C => 1 }", "[complex]")
{
	frequency_map frequencies;
	frequencies['A'] = 4;
	frequencies['B'] = 2;
	frequencies['C'] = 1;

	std::shared_ptr<bintree> root = build_tree(frequencies);

	require_eof_path(root, "000");
	require_datum_path(root, "001", 'C', 1);
	require_datum_path(root, "01", 'B', 2);
	require_datum_path(root, "1", 'A', 4);
}

#include "Catch.h"
#include "huffman_tree.h"

std::shared_ptr<const leaf> get_leaf(std::shared_ptr<const huffman_tree> root, std::string code)
{
	auto current = root;

	for (char c : code)
	{
		auto b = std::dynamic_pointer_cast<const branch>(current);

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

	auto lf = std::dynamic_pointer_cast<const leaf>(current);

	REQUIRE(lf != nullptr);

	return lf;
}

void require_path(std::shared_ptr<const huffman_tree> root, std::string code, uint8_t datum, unsigned weight)
{
	auto lf = std::dynamic_pointer_cast<const leaf>(get_leaf(root, code));

	REQUIRE(lf != nullptr);	
	REQUIRE(lf->datum() == datum);
}

TEST_CASE("Creating tree for { A => 1 }", "[build_tree]")
{
	frequency_map frequencies;
	frequencies['A'] = 1;

	std::shared_ptr<huffman_tree> root = build_tree(frequencies);

	require_path(root, "", 'A', 1);
}

TEST_CASE("Creating tree for { A => 2 }", "[build_tree]")
{
	frequency_map frequencies;
	frequencies['A'] = 2;

	std::shared_ptr<huffman_tree> root = build_tree(frequencies);

	require_path(root, "", 'A', 2);
}

TEST_CASE("Creating tree for { B => 1 }", "[build_tree]")
{
	frequency_map frequencies;
	frequencies['B'] = 1;

	std::shared_ptr<huffman_tree> root = build_tree(frequencies);

	require_path(root, "", 'B', 1);
}

TEST_CASE("Creating tree for { A => 2, B => 4, X => 1 }", "[build_tree]")
{
	frequency_map frequencies;
	frequencies['A'] = 2;
	frequencies['B'] = 4;
	frequencies['X'] = 1;

	std::shared_ptr<huffman_tree> root = build_tree(frequencies);

	require_path(root, "00", 'X', 1);
	require_path(root, "01", 'A', 2);
	require_path(root, "1", 'B', 4);
}

TEST_CASE("Creating tree for { A => 2, B => 4, C => 8, X => 1 }", "[build_tree]")
{
	frequency_map frequencies;
	frequencies['A'] = 2;
	frequencies['B'] = 4;
	frequencies['C'] = 8;
	frequencies['X'] = 1;

	std::shared_ptr<huffman_tree> root = build_tree(frequencies);

	require_path(root, "000", 'X', 1);
	require_path(root, "001", 'A', 2);
	require_path(root, "01", 'B', 4);
	require_path(root, "1", 'C', 8);
}

TEST_CASE("Creating tree for { A => 8, B => 4, C => 2 }", "[build_tree]")
{
	frequency_map frequencies;
	frequencies['A'] = 8;
	frequencies['B'] = 4;
	frequencies['C'] = 2;
	frequencies['X'] = 1;
	
	std::shared_ptr<huffman_tree> root = build_tree(frequencies);

	require_path(root, "000", 'X', 1);
	require_path(root, "001", 'C', 2);
	require_path(root, "01", 'B', 4);
	require_path(root, "1", 'A', 8);
}

TEST_CASE("Creating tree for { A => 23, B => 59, C => 8, D => 40, E => 100, F => 33 }", "[build_tree]")
{
	frequency_map frequencies;
	frequencies['A'] = 23;
	frequencies['B'] = 59;
	frequencies['C'] = 8;
	frequencies['D'] = 40;
	frequencies['E'] = 100;
	frequencies['F'] = 33;
	frequencies['X'] = 1;

	std::shared_ptr<huffman_tree> root = build_tree(frequencies);

	require_path(root, "10000", 'X', 1);
	require_path(root, "1001", 'A', 23);
	require_path(root, "111", 'B', 59);
	require_path(root, "10001", 'C', 8);
	require_path(root, "110", 'D', 40);
	require_path(root, "0", 'E', 100);
	require_path(root, "101", 'F', 33);
}

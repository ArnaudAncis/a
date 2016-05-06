#include "Catch.h"
#include "encoder.h"
#include "bit_sequence_test_aux.h"

TEST_CASE("Encoder for { }", "[encoder]")
{
	frequency_map frequencies;
	std::shared_ptr<huffman_tree> root = build_tree(frequencies);

	encoder enc(*root);

	REQUIRE(enc.eof() == bit_sequence::empty());
}

TEST_CASE("Encoder for { A => 2 }", "[encoder]")
{
	frequency_map frequencies;
	frequencies['A'] = 2;
	std::shared_ptr<huffman_tree> root = build_tree(frequencies);

	encoder enc(*root);

	REQUIRE(enc.eof() == parse_bit_sequence("0"));
	REQUIRE(enc['A'] == parse_bit_sequence("1"));
}

TEST_CASE("Encoder for { B => 2 }", "[encoder]")
{
	frequency_map frequencies;
	frequencies['B'] = 2;
	std::shared_ptr<huffman_tree> root = build_tree(frequencies);

	encoder enc(*root);

	REQUIRE(enc.eof() == parse_bit_sequence("0"));
	REQUIRE(enc['B'] == parse_bit_sequence("1"));
}

TEST_CASE("Encoder for { A => 2, B => 4 }", "[encoder]")
{
	frequency_map frequencies;
	frequencies['A'] = 2;
	frequencies['B'] = 4;
	std::shared_ptr<huffman_tree> root = build_tree(frequencies);

	encoder enc(*root);

	REQUIRE(enc.eof() == parse_bit_sequence("00"));
	REQUIRE(enc['A'] == parse_bit_sequence("01"));
	REQUIRE(enc['B'] == parse_bit_sequence("1"));
}

TEST_CASE("Encoder for { A => 2, B => 4, C => 8 }", "[encoder]")
{
	frequency_map frequencies;
	frequencies['A'] = 2;
	frequencies['B'] = 4;
	frequencies['C'] = 8;

	std::shared_ptr<huffman_tree> root = build_tree(frequencies);
	encoder enc(*root);

	REQUIRE(enc.eof() == parse_bit_sequence("000"));
	REQUIRE(enc['A'] == parse_bit_sequence("001"));
	REQUIRE(enc['B'] == parse_bit_sequence("01"));
	REQUIRE(enc['C'] == parse_bit_sequence("1"));
}

TEST_CASE("Encoder for { A => 8, B => 4, C => 2 }", "[encoder]")
{
	frequency_map frequencies;
	frequencies['A'] = 8;
	frequencies['B'] = 4;
	frequencies['C'] = 2;

	std::shared_ptr<huffman_tree> root = build_tree(frequencies);
	encoder enc(*root);

	REQUIRE(enc.eof() == parse_bit_sequence("000"));
	REQUIRE(enc['C'] == parse_bit_sequence("001"));
	REQUIRE(enc['B'] == parse_bit_sequence("01"));
	REQUIRE(enc['A'] == parse_bit_sequence("1"));
}

TEST_CASE("Encoder for { A => 23, B => 59, C => 8, D => 40, E => 100, F => 33 }", "[encoder]")
{
	frequency_map frequencies;
	frequencies['A'] = 23;
	frequencies['B'] = 59;
	frequencies['C'] = 8;
	frequencies['D'] = 40;
	frequencies['E'] = 100;
	frequencies['F'] = 33;

	std::shared_ptr<huffman_tree> root = build_tree(frequencies);
	encoder enc(*root);

	REQUIRE(enc.eof() == parse_bit_sequence("10000"));
	REQUIRE(enc['A'] == parse_bit_sequence("1001"));
	REQUIRE(enc['B'] == parse_bit_sequence("111"));
	REQUIRE(enc['C'] == parse_bit_sequence("10001"));
	REQUIRE(enc['D'] == parse_bit_sequence("110"));
	REQUIRE(enc['E'] == parse_bit_sequence("0"));
	REQUIRE(enc['F'] == parse_bit_sequence("101"));
}

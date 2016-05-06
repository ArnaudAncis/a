#include "bit_sequence.h"
#include "bit_sequence_test_aux.h"
#include "Catch.h"

TEST_CASE("Empty sequence", "[bit_sequence]")
{
	auto bs = bit_sequence::empty();

	REQUIRE(bs.length() == 0);
}

TEST_CASE("Zero", "[bit_sequence]")
{
	const auto bs = bit_sequence::zero();

	REQUIRE(bs.length() == 1);
	REQUIRE(bs[0] == false);
}

TEST_CASE("One", "[bit_sequence]")
{
	const auto bs = bit_sequence::one();

	REQUIRE(bs.length() == 1);
	REQUIRE(bs[0] == true);
}

TEST_CASE("Construction with false", "[bit_sequence]")
{
	bit_sequence bs = false;

	REQUIRE(bs.length() == 1);
	REQUIRE(bs[0] == false);
}

TEST_CASE("Construction with true", "[bit_sequence]")
{
	bit_sequence bs = true;

	REQUIRE(bs.length() == 1);
	REQUIRE(bs[0] == true);
}

TEST_CASE("+ false", "[bit_sequence]")
{
	bit_sequence xs = true;
	auto bs = xs + false;

	REQUIRE(bs.length() == 2);
	REQUIRE(bs[0] == true);
	REQUIRE(bs[1] == false);
}

TEST_CASE("+ true", "[bit_sequence]")
{
	bit_sequence xs = true;
	auto bs = xs + true;

	REQUIRE(bs.length() == 2);
	REQUIRE(bs[0] == true);
	REQUIRE(bs[1] == true);
}

TEST_CASE("+= false", "[bit_sequence]")
{
	bit_sequence bs = true;
	bs += false;

	REQUIRE(bs.length() == 2);
	REQUIRE(bs[0] == true);
	REQUIRE(bs[1] == false);
}

TEST_CASE("+= true", "[bit_sequence]")
{
	bit_sequence bs = true;
	bs += true;

	REQUIRE(bs.length() == 2);
	REQUIRE(bs[0] == true);
	REQUIRE(bs[1] == true);
}

TEST_CASE("+ other_bitsequence", "[bit_sequence]")
{
	bit_sequence xs = true;
	(xs += true) += false;
	bit_sequence ys = true;
	(ys += false) += true;
	bit_sequence bs = xs + ys;

	REQUIRE(bs.length() == 6);
	REQUIRE(bs[0] == true);
	REQUIRE(bs[1] == true);
	REQUIRE(bs[2] == false);
	REQUIRE(bs[3] == true);
	REQUIRE(bs[4] == false);
	REQUIRE(bs[5] == true);
}

TEST_CASE("+= other_bitsequence", "[bit_sequence]")
{
	bit_sequence bs = true;
	(bs += true) += false;
	bit_sequence ys = true;
	(ys += false) += true;
	
	bs += ys;

	REQUIRE(bs.length() == 6);
	REQUIRE(bs[0] == true);
	REQUIRE(bs[1] == true);
	REQUIRE(bs[2] == false);
	REQUIRE(bs[3] == true);
	REQUIRE(bs[4] == false);
	REQUIRE(bs[5] == true);
}

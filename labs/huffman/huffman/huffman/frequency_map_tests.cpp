#include "Catch.h"
#include "frequency_map.h"
#include <limits>

TEST_CASE("Empty frequency map", "[frequency_map]")
{
	const frequency_map frequencies;

	for (uint16_t i = std::numeric_limits<uint8_t>::min(); i <= std::numeric_limits<uint8_t>::max(); ++i)
	{
		REQUIRE(frequencies[uint8_t(i)] == 0);
	}
}

TEST_CASE("Updating", "[frequency_map]")
{
	frequency_map frequencies;
	frequencies['A']++;

	REQUIRE(frequencies['A'] == 1);
}

TEST_CASE("Frequencies of A", "[frequency_map]")
{
	const auto freqs = frequencies("A");

	REQUIRE(freqs['A'] == 1);
	REQUIRE(freqs['B'] == 0);
	REQUIRE(freqs['C'] == 0);
}

TEST_CASE("Frequencies of AA", "[frequency_map]")
{
	const auto freqs = frequencies("AA");

	REQUIRE(freqs['A'] == 2);
	REQUIRE(freqs['B'] == 0);
	REQUIRE(freqs['C'] == 0);
}

TEST_CASE("Frequencies of AABBBC", "[frequency_map]")
{
	const auto freqs = frequencies("AABBBC");

	REQUIRE(freqs['A'] == 2);
	REQUIRE(freqs['B'] == 3);
	REQUIRE(freqs['C'] == 1);
}
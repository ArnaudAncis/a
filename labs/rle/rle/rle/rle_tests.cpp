/*

TESTS

*/

#include "Catch.h"
#include "rle.h"


void rle_test(uint8_t* input, unsigned input_size, uint8_t* expected, unsigned expected_size)
{
	auto actual = rle(input, input_size);

	REQUIRE(expected_size == actual.size());

	for (unsigned i = 0; i != expected_size; ++i)
	{
		REQUIRE(expected[i] == actual[i]);
	}
}


TEST_CASE("RLE on { }", "[rle]")
{
	auto result = rle(nullptr, 0);

	REQUIRE(result.size() == 0);
}

#define ARRAY(...) { __VA_ARGS__ }
#define RLE_TEST(INPUT, EXPECTED) TEST_CASE("RLE on " #INPUT, "[rle]") { uint8_t input[] = INPUT; uint8_t expected[] = EXPECTED; rle_test(input, sizeof(input) / sizeof(uint8_t), expected, sizeof(expected) / sizeof(uint8_t)); }

RLE_TEST(ARRAY(1), ARRAY(1, 1))
RLE_TEST(ARRAY(1, 1), ARRAY(2, 1))
RLE_TEST(ARRAY(1, 1, 1), ARRAY(3, 1))
RLE_TEST(ARRAY(2), ARRAY(1, 2))
RLE_TEST(ARRAY(2, 2), ARRAY(2, 2))
RLE_TEST(ARRAY(2, 2, 2), ARRAY(3, 2))
RLE_TEST(ARRAY(1, 2, 3), ARRAY(1, 1, 1, 2, 1, 3))
RLE_TEST(ARRAY(1, 1, 2, 2, 3, 3), ARRAY(2, 1, 2, 2, 2, 3))
RLE_TEST(ARRAY(1, 1, 1, 2, 2, 2, 3, 3, 3), ARRAY(3, 1, 3, 2, 3, 3))
RLE_TEST(ARRAY(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1), ARRAY(255, 1, 47, 1));

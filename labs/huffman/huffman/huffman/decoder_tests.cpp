#include "Catch.h"
#include "encoder.h"
#include "decoder.h"
#include "bit_sequence_test_aux.h"

void test_encode_decode(const std::string& string)
{
	auto freqs = frequencies(string);
	auto root = build_tree(freqs);
	encoder enc(*root);
	auto compressed = enc[string];
	decoder dec(root);
	auto decompressed = dec.decode(compressed);

	REQUIRE(string == decompressed);
}

#define ENCODE_DECODE(DATA) TEST_CASE("Encode/decode " #DATA, "[decoder]") { test_encode_decode(DATA); }

ENCODE_DECODE("ABB")
ENCODE_DECODE("BAB")
ENCODE_DECODE("BBA")
ENCODE_DECODE("XYX")
ENCODE_DECODE("ABBCCCCDDDDDDDD")
ENCODE_DECODE("FJKLDCJLKQOFJIDFJIOCJKLJLKJLFKJ")
ENCODE_DECODE("FJKLDCJLKQOFJIDFJIOCJKLJLKJLFKJLKJL")
ENCODE_DECODE("JQFJLJPJFJKJFLDJLKJCQRFOIFCKJSCJKLCJKLJFLQJIOFJCDIFHJHFKJ")
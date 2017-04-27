#ifdef TEST_BUILD
#define CATCH_CONFIG_MAIN
#include "lz77.h"
#include "Catch.h"


TEST_CASE("match_length")
{
    CHECK(match_length("abc", "abc") == 3);
    CHECK(match_length("abc", "abcd") == 3);
    CHECK(match_length("abcd", "abc") == 3);
    CHECK(match_length("abc", "abce") == 3);
    CHECK(match_length("", "xyz") == 0);
    CHECK(match_length("x", "xyz") == 1);
    CHECK(match_length("xy", "xyz") == 2);
}

TEST_CASE("find_longest_match('abcabc', 3, 3)")
{
    unsigned distance, length;

    find_longest_match("abcabc", 3, 3, &distance, &length);

    CHECK(distance == 3);
    CHECK(length == 3);
}

TEST_CASE("find_longest_match('abcxabc', 4, 3)")
{
    unsigned distance, length;

    find_longest_match("abcxabc", 4, 3, &distance, &length);

    CHECK(distance == 4);
    CHECK(length == 3);
}

TEST_CASE("find_longest_match('abcxyz', 3, 3)")
{
    unsigned distance, length;

    find_longest_match("abcxyz", 3, 3, &distance, &length);

    CHECK(distance == 0);
    CHECK(length == 0);
}

TEST_CASE("find_longest_match('aaaa', 1, 5)")
{
    unsigned distance, length;

    find_longest_match("aaaa", 1, 5, &distance, &length);

    CHECK(distance == 1);
    CHECK(length == 3);
}

TEST_CASE("find_longest_match('abcdabcd', 4, 3)")
{
    unsigned distance, length;

    find_longest_match("abcdabcd", 4, 3, &distance, &length);

    CHECK(distance == 4);
    CHECK(length == 3);
}

TEST_CASE("find_longest_match('aababcabcdabcd', 10, 5)")
{
    unsigned distance, length;

    find_longest_match("aababcabcdabcd", 10, 5, &distance, &length);

    CHECK(distance == 4);
    CHECK(length == 4);
}

TEST_CASE("encode(10, 10, 'a')")
{
    std::string s = "a";
    auto result = encode(10, 10, s);

    REQUIRE(result.size() == 1);
    CHECK(result[0].distance == 0);
    CHECK(result[0].length == 0);
    CHECK(result[0].datum == 'a');
}

TEST_CASE("encode(10, 10, 'aa')")
{
    std::string s = "aa";
    auto result = encode(10, 10, s);

    REQUIRE(result.size() == 2);
    CHECK(result[0].distance == 0);
    CHECK(result[0].length == 0);
    CHECK(result[0].datum == 'a');
    CHECK(result[1].distance == 0);
    CHECK(result[1].length == 0);
    CHECK(result[1].datum == 'a');
}

TEST_CASE("encode(10, 10, 'aaa')")
{
    std::string s = "aaa";
    auto result = encode(10, 10, s);

    REQUIRE(result.size() == 2);
    CHECK(result[0].distance == 0);
    CHECK(result[0].length == 0);
    CHECK(result[0].datum == 'a');
    CHECK(result[1].distance == 1);
    CHECK(result[1].length == 1);
    CHECK(result[1].datum == 'a');
}

TEST_CASE("encode(10, 10, 'aaaa')")
{
    std::string s = "aaaa";
    auto result = encode(10, 10, s);

    REQUIRE(result.size() == 2);
    CHECK(result[0].distance == 0);
    CHECK(result[0].length == 0);
    CHECK(result[0].datum == 'a');
    CHECK(result[1].distance == 1);
    CHECK(result[1].length == 2);
    CHECK(result[1].datum == 'a');
}

TEST_CASE("encode(10, 10, 'abcabcabc')")
{
    std::string s = "abcabcabc";
    auto result = encode(10, 10, s);

    REQUIRE(result.size() == 4);
    CHECK(result[0].distance == 0);
    CHECK(result[0].length == 0);
    CHECK(result[0].datum == 'a');
    CHECK(result[1].distance == 0);
    CHECK(result[1].length == 0);
    CHECK(result[1].datum == 'b');
    CHECK(result[2].distance == 0);
    CHECK(result[2].length == 0);
    CHECK(result[2].datum == 'c');
    CHECK(result[3].distance == 3);
    CHECK(result[3].length == 5);
    CHECK(result[3].datum == 'c');
}

#endif

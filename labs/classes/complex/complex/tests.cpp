// Set this macro to 1 and increment it as you implement more members of the class complex
// As last step, set this macro to 9999 to ensure you run all tests
#define TEST_LEVEL 9999


/*

TESTS

*/

#define CATCH_CONFIG_MAIN
#include "Catch.h"
#include "complex.h"



#if 1 <= TEST_LEVEL

TEST_CASE("Creating complex using zero arguments", "[complex]")
{
    complex c;

    REQUIRE(c.re() == Approx(0));
    REQUIRE(c.im() == Approx(0));
}

TEST_CASE("Creating complex using single argument", "[complex]")
{
    complex c(5);

    REQUIRE(c.re() == Approx(5));
    REQUIRE(c.im() == Approx(0));
}

TEST_CASE("Creating complex using both arguments", "[complex]")
{
    complex c(5, 9);

    REQUIRE(c.re() == Approx(5));
    REQUIRE(c.im() == Approx(9));
}

#endif


#if 2 <= TEST_LEVEL

TEST_CASE("Modifying re", "[complex]")
{
    complex c;

    REQUIRE(c.re() == Approx(0));
    REQUIRE(c.im() == Approx(0));

    c.re() = 10;

    REQUIRE(c.re() == Approx(10));
    REQUIRE(c.im() == Approx(0));
}

TEST_CASE("Modifying im", "[complex]")
{
    complex c;

    REQUIRE(c.re() == Approx(0));
    REQUIRE(c.im() == Approx(0));

    c.im() = 50;

    REQUIRE(c.re() == Approx(0));
    REQUIRE(c.im() == Approx(50));
}

#endif


#if 3 <= TEST_LEVEL

TEST_CASE("Copy constructor", "[complex]")
{
    complex c1(5, 8);
    complex c2 = c1;

    REQUIRE(c1.re() == Approx(c2.re()));
    REQUIRE(c1.im() == Approx(c2.im()));
}

#endif


#if 4 <= TEST_LEVEL

TEST_CASE("Addition", "[complex]")
{
    complex c1(1, 2);
    complex c2(5, 3);
    complex c3 = c1.add(c2);

    REQUIRE(c3.re() == Approx(6));
    REQUIRE(c3.im() == Approx(5));
}

#endif


#if 5 <= TEST_LEVEL

TEST_CASE("Negation", "[complex]")
{
    complex c1(1, 2);
    complex c2 = c1.neg();

    REQUIRE(c2.re() == Approx(-1));
    REQUIRE(c2.im() == Approx(-2));
}

#endif


#if 6 <= TEST_LEVEL

TEST_CASE("Subtraction", "[complex]")
{
    complex c1(1, 2);
    complex c2(5, 3);
    complex c3 = c1.sub(c2);

    REQUIRE(c3.re() == Approx(-4));
    REQUIRE(c3.im() == Approx(-1));
}

#endif


#if 7 <= TEST_LEVEL

TEST_CASE("Multiplication", "[complex]")
{
    const double a = 5;
    const double b = 2;
    const double c = 7;
    const double d = 9;

    complex c1(a, b);
    complex c2(c, d);
    complex c3 = c1.mul(c2);

    REQUIRE(c3.re() == Approx(a * c - b * d));
    REQUIRE(c3.im() == Approx(b * c + a * d));
}

#endif


#if 8 <= TEST_LEVEL

TEST_CASE("Reciprocal", "[complex]")
{
    const double a = 5;
    const double b = 2;

    complex c1(a, b);
    complex c2 = c1.reciprocal();

    REQUIRE(c2.re() == Approx(a / (a * a + b * b)));
    REQUIRE(c2.im() == Approx(-b / (a * a + b * b)));
}

TEST_CASE("Reciprocal on 0.5 + 0.5i", "[complex]")
{
    const double a = 0.5;
    const double b = 0.5;

    complex c1(a, b);
    complex c2 = c1.reciprocal();

    REQUIRE(c2.re() == Approx(1));
    REQUIRE(c2.im() == Approx(-1));
}

#endif


#if 9 <= TEST_LEVEL

TEST_CASE("Division", "[complex]")
{
    complex c1(16, 24);
    complex c2(4, 6);
    complex c3 = c1.div(c2);

    REQUIRE(c3.re() == Approx(4));
    REQUIRE(c3.im() == Approx(0));
}

#endif


#if 10 <= TEST_LEVEL

TEST_CASE("Conjugate", "[complex]")
{
    complex c1(7, 1);
    complex c2 = c1.conj();

    REQUIRE(c2.re() == Approx(7));
    REQUIRE(c2.im() == Approx(-1));
}

#endif


#if 11 <= TEST_LEVEL

TEST_CASE("Absolute value", "[complex]")
{
    complex c1(3, 4);
    double a = c1.abs();

    REQUIRE(a == Approx(5));
}

#endif
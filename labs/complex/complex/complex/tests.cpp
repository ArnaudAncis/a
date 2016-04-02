/*

TESTS

*/

#define CATCH_CONFIG_MAIN
#include "Catch.h"
#include "complex.h"



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

TEST_CASE("Creating complex with nonintegers", "[complex]")
{
    complex c(5.2, 9.6);

    REQUIRE(c.re() == Approx(5.2));
    REQUIRE(c.im() == Approx(9.6));
}

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

TEST_CASE("Copy constructor", "[complex]")
{
    complex c1(5, 8);
    complex c2 = c1;

    REQUIRE(c1.re() == Approx(c2.re()));
    REQUIRE(c1.im() == Approx(c2.im()));
}

TEST_CASE("Addition", "[complex]")
{
    complex c1(1, 2);
    complex c2(5, 3);
    complex c3 = c1 + c2;

    REQUIRE(c3.re() == Approx(6));
    REQUIRE(c3.im() == Approx(5));
}

TEST_CASE("Negation", "[complex]")
{
    complex c1(1, 2);
    complex c2 = -c1;

    REQUIRE(c2.re() == Approx(-1));
    REQUIRE(c2.im() == Approx(-2));
}

TEST_CASE("Subtraction", "[complex]")
{
    complex c1(1, 2);
    complex c2(5, 3);
    complex c3 = c1 - c2;

    REQUIRE(c3.re() == Approx(-4));
    REQUIRE(c3.im() == Approx(-1));
}

TEST_CASE("Multiplication", "[complex]")
{
    const double a = 5;
    const double b = 2;
    const double c = 7;
    const double d = 9;

    complex c1(a, b);
    complex c2(c, d);
    complex c3 = c1 * c2;

    REQUIRE(c3.re() == Approx(a * c - b * d));
    REQUIRE(c3.im() == Approx(b * c + a * d));
}

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

TEST_CASE("Division", "[complex]")
{
    complex c1(16, 24);
    complex c2(4, 6);
    complex c3 = c1 / c2;

    REQUIRE(c3.re() == Approx(4));
    REQUIRE(c3.im() == Approx(0));
}

TEST_CASE("Conjugate", "[complex]")
{
    complex c1(7, 1);
    complex c2 = c1.conj();

    REQUIRE(c2.re() == Approx(7));
    REQUIRE(c2.im() == Approx(-1));
}

TEST_CASE("Absolute value", "[complex]")
{
    complex c1(3, 4);
    double a = c1.abs();

    REQUIRE(a == Approx(5));
}

TEST_CASE("Assignment", "[complex]")
{
    complex c1(6, 3);
    complex c2(1, 9);

    REQUIRE(c1.re() == Approx(6));
    REQUIRE(c1.im() == Approx(3));
    REQUIRE(c2.re() == Approx(1));
    REQUIRE(c2.im() == Approx(9));

    c1 = c2;

    REQUIRE(c1.re() == Approx(1));
    REQUIRE(c1.im() == Approx(9));
    REQUIRE(c2.re() == Approx(1));
    REQUIRE(c2.im() == Approx(9));
}

TEST_CASE("Operator +=", "[complex]")
{
    complex c1(6, 3);
    complex c2(1, 9);

    c1 += c2;

    REQUIRE(c1.re() == Approx(7));
    REQUIRE(c1.im() == Approx(12));
}

TEST_CASE("Operator -=", "[complex]")
{
    complex c1(6, 3);
    complex c2(1, 9);

    c1 -= c2;

    REQUIRE(c1.re() == Approx(5));
    REQUIRE(c1.im() == Approx(-6));
}

TEST_CASE("Operator *=", "[complex]")
{
    complex c1(6, 3);
    complex c2(1, 9);

    c1 *= c2;

    REQUIRE(c1.re() == Approx(-21));
    REQUIRE(c1.im() == Approx(57));
}

TEST_CASE("Operator /=", "[complex]")
{
    complex c1(6, 3);
    complex c2(1, 9);

    c1 /= c2;

    REQUIRE(c1.re() == Approx(0.402439));
    REQUIRE(c1.im() == Approx(-0.621951));
}
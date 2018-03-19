#include "string-parameter.h"
#include "string-parameter.h"
#include "Catch.h"


TEST_CASE("String parameter: zero arguments")
{
	std::list<std::string> args = {};
	std::shared_ptr<StringParameter> p = string("verbose", "");

	CHECK(p->value() == "");
	p->parse(args);
	CHECK(p->value() == "");
	CHECK(args.empty());
}

TEST_CASE("String parameter: wrong argument")
{
	std::list<std::string> args = { "--test", "foo" };
	std::shared_ptr<StringParameter> p = string("verbose", "xyz");

	CHECK(p->value() == "xyz");
	p->parse(args);
	CHECK(p->value() == "xyz");

	REQUIRE(args.size() == 2);
	auto it = args.begin();
	CHECK(*it == "--test");
	it++;
	CHECK(*it == "foo");
}

TEST_CASE("String parameter: right argument")
{
	std::list<std::string> args = { "--file", "foo", "--n" };
	std::shared_ptr<StringParameter> p = string("file", "");

	CHECK(p->value() == "");
	p->parse(args);
	CHECK(p->value() == "foo");

	REQUIRE(args.size() == 1);
	auto it = args.begin();
	CHECK(*it == "--n");
}

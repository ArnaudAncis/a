#include "flag-parameter.h"
#include "flag-parameter.h"
#include "Catch.h"


TEST_CASE("Flag parameter: zero arguments")
{
	std::list<std::string> args = { };
	std::shared_ptr<FlagParameter> p = flag("verbose");

	CHECK(p->is_set() == false);
	p->parse(args);
	CHECK(p->is_set() == false);
	CHECK(args.empty());
}

TEST_CASE("Flag parameter: wrong argument")
{
	std::list<std::string> args = { "--test", "foo" };
	std::shared_ptr<FlagParameter> p = flag("verbose");

	CHECK(p->is_set() == false);
	p->parse(args);
	CHECK(p->is_set() == false);

	REQUIRE(args.size() == 2);
	auto it = args.begin();
	CHECK(*it == "--test");
	it++;
	CHECK(*it == "foo");
}

TEST_CASE("Flag parameter: right argument")
{
	std::list<std::string> args = { "--verbose", "foo" };
	std::shared_ptr<FlagParameter> p = flag("verbose");

	CHECK(p->is_set() == false);
	p->parse(args);
	CHECK(p->is_set() == true);

	REQUIRE(args.size() == 1);
	auto it = args.begin();
	CHECK(*it == "foo");
}

#include "parser.h"
#include "parser.h"
#include "flag-parameter.h"
#include "flag-parameter.h"
#include "string-parameter.h"
#include "string-parameter.h"
#include "Catch.h"


TEST_CASE("Parsing --flag")
{
    Parser parser;
    auto f = flag("flag");
    parser.add_parameter(f);

    const Parser& p = parser;

    std::list<std::string> args = { "--flag" };
    p.parse(args);

    CHECK(f->is_set());
    CHECK(args.empty());
}

TEST_CASE("Parsing --flag1 --flag2")
{
    Parser parser;
    auto f1 = flag("flag1");
    auto f2 = flag("flag2");
    parser.add_parameter(f1).add_parameter(f2);

    std::list<std::string> args = { "--flag1", "--flag2" };
    parser.parse(args);

    CHECK(f1->is_set());
    CHECK(f2->is_set());
    CHECK(args.empty());
}

TEST_CASE("Parsing --flag2 --flag1")
{
    Parser parser;
    auto f1 = flag("flag1");
    auto f2 = flag("flag2");
    parser.add_parameter(f1).add_parameter(f2);

    std::list<std::string> args = { "--flag2", "--flag1" };
    parser.parse(args);

    CHECK(f1->is_set());
    CHECK(f2->is_set());
    CHECK(args.empty());
}

TEST_CASE("Parsing --flag1 --flag2 foo")
{
    Parser parser;
    auto f1 = flag("flag1");
    auto f2 = flag("flag2");
    parser.add_parameter(f1).add_parameter(f2);

    std::list<std::string> args = { "--flag1", "--flag2", "foo" };
    parser.parse(args);

    CHECK(f1->is_set());
    CHECK(f2->is_set());
    CHECK(args.size() == 1);
    CHECK(args.front() == "foo");
}

TEST_CASE("Parsing --string xyz")
{
    Parser parser;
    auto str = string("string", "");
    parser.add_parameter(str);

    std::list<std::string> args = { "--string", "xyz" };
    parser.parse(args);

    CHECK(str->value() == "xyz");
    CHECK(args.empty());
}

TEST_CASE("Parsing --string abc --flag 5")
{
    Parser parser;
    auto str = string("string", "");
    auto f = flag("flag");
    parser.add_parameter(str).add_parameter(f);

    std::list<std::string> args = { "--string", "abc", "--flag", "5" };
    parser.parse(args);

    CHECK(str->value() == "abc");
    CHECK(f->is_set());
    CHECK(args.size() == 1);
    CHECK(args.front() == "5");
}

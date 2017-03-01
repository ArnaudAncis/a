#define CATCH_CONFIG_MAIN
#include "linked_list.h"
#include "Catch.h"
#include <vector>
#include <memory>


void destroy(linked_list* lst)
{
    linked_list* next;

    while (lst != nullptr)
    {
        next = lst->next;
        delete lst;
        lst = next;
    }
}

std::shared_ptr<linked_list> create(const std::vector<int>& xs)
{
    linked_list* result = nullptr;

    for (auto i = xs.rbegin(); i != xs.rend(); ++i)
    {
        result = new linked_list{ *i, result };
    }

    return std::shared_ptr<linked_list>(result, destroy);
}




TEST_CASE("Length of empty list")
{
    std::vector<int> ns{};
    auto lst = create(ns);

    REQUIRE(ns.size() == length(lst.get()));
}

TEST_CASE("Length of {1}")
{
    std::vector<int> ns{1};
    auto lst = create(ns);

    REQUIRE(ns.size() == length(lst.get()));
}

TEST_CASE("Length of {1, 2}")
{
    std::vector<int> ns{ 1, 2 };
    auto lst = create(ns);

    REQUIRE(ns.size() == length(lst.get()));
}

TEST_CASE("Length of {1, 2, 3}")
{
    std::vector<int> ns{ 1, 2, 3 };
    auto lst = create(ns);

    REQUIRE(ns.size() == length(lst.get()));
}

TEST_CASE("Making {1} cyclic")
{
    linked_list a{ 1, nullptr };

    make_cyclic(&a);

    REQUIRE(a.next == &a);
}

TEST_CASE("Making {1, 2} cyclic")
{
    linked_list a{ 1, nullptr };
    linked_list b{ 2, nullptr };
    a.next = &b;

    make_cyclic(&a);

    REQUIRE(a.next == &b);
    REQUIRE(b.next == &a);
}

TEST_CASE("Making {1, 2, 3} cyclic")
{
    linked_list a{ 1, nullptr };
    linked_list b{ 2, nullptr };
    linked_list c{ 3, nullptr };
    a.next = &b;
    b.next = &c;

    make_cyclic(&a);

    REQUIRE(a.next == &b);
    REQUIRE(b.next == &c);
    REQUIRE(c.next == &a);
}

TEST_CASE("{} has no cycle")
{
    std::vector<int> ns{};
    auto lst = create(ns);

    REQUIRE(!has_cycle(lst.get()));
}

TEST_CASE("{1} has no cycle")
{
    std::vector<int> ns{1};
    auto lst = create(ns);

    REQUIRE(!has_cycle(lst.get()));
}

TEST_CASE("{1, 2} has no cycle")
{
    std::vector<int> ns{ 1, 2 };
    auto lst = create(ns);

    REQUIRE(!has_cycle(lst.get()));
}

TEST_CASE("{1, 2, 3} has no cycle")
{
    std::vector<int> ns{ 1, 2, 3 };
    auto lst = create(ns);

    REQUIRE(!has_cycle(lst.get()));
}

TEST_CASE("{[1]} has a cycle")
{
    linked_list a{ 1, nullptr };
    a.next = &a;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{[1, 2]} has a cycle")
{
    linked_list a{ 1, nullptr };
    linked_list b{ 2, nullptr };
    a.next = &b;
    b.next = &a;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{[1, 2, 3]} has a cycle")
{
    linked_list a{ 1, nullptr };
    linked_list b{ 2, nullptr };
    linked_list c{ 3, nullptr };
    a.next = &b;
    b.next = &c;
    c.next = &a;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{1, 2, [3]} has a cycle")
{
    linked_list a{ 1, nullptr };
    linked_list b{ 2, nullptr };
    linked_list c{ 3, nullptr };
    a.next = &b;
    b.next = &c;
    c.next = &c;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{1, [2, 3]} has a cycle")
{
    linked_list a{ 1, nullptr };
    linked_list b{ 2, nullptr };
    linked_list c{ 3, nullptr };
    a.next = &b;
    b.next = &c;
    c.next = &b;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{1, [2, 3, 4]} has a cycle")
{
    linked_list a{ 1, nullptr };
    linked_list b{ 2, nullptr };
    linked_list c{ 3, nullptr };
    linked_list d{ 4, nullptr };
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &b;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{1, 2, [3, 4]} has a cycle")
{
    linked_list a{ 1, nullptr };
    linked_list b{ 2, nullptr };
    linked_list c{ 3, nullptr };
    linked_list d{ 4, nullptr };
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &c;

    REQUIRE(has_cycle(&a));
}

TEST_CASE("{1, 2, 3, [4]} has a cycle")
{
    linked_list a{ 1, nullptr };
    linked_list b{ 2, nullptr };
    linked_list c{ 3, nullptr };
    linked_list d{ 4, nullptr };
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &d;

    REQUIRE(has_cycle(&a));
}

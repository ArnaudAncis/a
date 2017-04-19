#ifdef TEST_BUILD

#include "streams/demultiplexer.h"
#include "tests/testlib.h"
#include "Catch.h"


TEST_CASE("demultiplexing {}")
{
    auto s = STREAM(int);
    Demultiplexer<int> demux(s);

    REQUIRE(demux.left_channel->size() == 0);
    REQUIRE(demux.right_channel->size() == 0);
}

TEST_CASE("demultiplexing {0,1}")
{
    auto s = STREAM(int, 0, 1);
    Demultiplexer<int> demux(s);

    REQUIRE(demux.left_channel->size() == 1);
    REQUIRE((*demux.left_channel)[0] == 0);
    REQUIRE(demux.right_channel->size() == 1);
    REQUIRE((*demux.right_channel)[0] == 1);
}

TEST_CASE("demultiplexing {0,1,2,3}")
{
    auto s = STREAM(int, 0, 1, 2, 3);
    Demultiplexer<int> demux(s);

    REQUIRE(demux.left_channel->size() == 2);
    REQUIRE((*demux.left_channel)[0] == 0);
    REQUIRE((*demux.left_channel)[1] == 2);
    REQUIRE(demux.right_channel->size() == 2);
    REQUIRE((*demux.right_channel)[0] == 1);
    REQUIRE((*demux.right_channel)[1] == 3);
}

#endif

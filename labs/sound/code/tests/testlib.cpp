#ifdef TEST_BUILD

#include "tests/testlib.h"
#include "Catch.h"


void check_equal_waves(Wave a, Wave b, double dt)
{
    REQUIRE(a.length() == Approx(b.length()));
    
    for (double t = 0; t < a.length(); t += dt)
    {
        CHECK(a[t] == Approx(b[t]));
    }
}

#endif
#include "tests/testlib.h"
#include "Catch.h"


void check_same_wave(Wave a, Wave b, double dt)
{
    REQUIRE(a.length() == Approx(b.length()));
    
    for (double t = 0; t < a.length(); t += dt)
    {
        CHECK(a[t] == Approx(b[t]));
    }
}
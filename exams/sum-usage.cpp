std::vector<double> ns = { 1, 2, 3 };
const std::vector<double>& ms = ns;

REQUIRE( sum(ms) == 6 )

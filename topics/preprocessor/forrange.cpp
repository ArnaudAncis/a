#define FORRANGE(i, from, to) \
  for ( int i = from; i <= to; ++i )

FORRANGE(i, 1, 10) {
  std::cout << i << std::endl;
}

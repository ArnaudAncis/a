int count_zeros(const std::vector<int>* ns) {
  int result = 0;

  for ( int n : *ns ) {
    if ( n == 0 ) ++result;
  }

  return result;
}

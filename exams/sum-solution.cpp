double sum(const std::vector<double>& ns) {
  double total = 0;

  for ( double n : ns )
    total += n;

  return total;
}

void sum(const std::vector<int>* xs)
{
  int total;

  for ( int x : *xs )
  {
    total += x;
  }

  return total;
}

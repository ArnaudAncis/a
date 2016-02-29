int sum(const std::vector<int>* xs)
{
  int total;

  for ( int x : *xs )
  {
    total += x;
  }

  // Won't compile
  (*xs).pop_back();

  return total;
}

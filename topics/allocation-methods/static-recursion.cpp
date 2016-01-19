// Computes sum 1...n
int sum(int n)
{
  if ( n == 0 ) return 0;
  else return n + sum(n - 1);
}

sum(5); // returns `\only<1>{?}\only<2>{0}`

// Outside class
TimeSpan operator *(int n, const TimeSpan& ts)
{
  return ts * n;
}

class TimeSpan
{
  TimeSpan operator -(const TimeSpan& other) const
  {
      return TimeSpan(seconds - other.seconds);
  }

  TimeSpan operator *(int n) const
  {
      return TimeSpan(seconds * n);
  }

  TimeSpan operator /(int n) const
  {
      return TimeSpan(seconds / n);
  }
};

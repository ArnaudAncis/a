class TimeSpan
{
  TimeSpan operator -() const
  {
    return TimeSpan(-totalSeconds);
  }
};

class TimeSpan
{
  // ...

  friend TimeSpan operator +(const TimeSpan& ts1,
                             const TimeSpan& ts2);
};

TimeSpan operator +(const TimeSpan& ts1,
                    const TimeSpan& ts2)
{
  // Can access private members
  return TimeSpan(ts1.seconds + ts2.seconds);
}

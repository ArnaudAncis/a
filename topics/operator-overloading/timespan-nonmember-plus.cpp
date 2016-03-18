TimeSpan operator +(const TimeSpan& ts1,
                    const TimeSpan& ts2)
{
  // Error: seconds is private
  return TimeSpan(ts1.seconds + ts2.seconds);
}

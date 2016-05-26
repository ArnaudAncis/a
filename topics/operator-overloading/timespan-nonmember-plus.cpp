TimeSpan operator +(const TimeSpan& ts1,
                    const TimeSpan& ts2)
{
  // Error: seconds is private
  return TimeSpan(ts1.totalSeconds +
                  ts2.totalSeconds);
}

class TimeSpan {
  TimeSpan operator -(const TimeSpan& other) const {
      return TimeSpan(totalSeconds -
                      other.totalSeconds);
  }

  TimeSpan operator *(int n) const {
      return TimeSpan(totalSeconds * n);
  }

  TimeSpan operator /(int n) const {
      return TimeSpan(totalSeconds / n);
  }
};

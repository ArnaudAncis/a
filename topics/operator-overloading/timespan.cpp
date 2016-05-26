class TimeSpan {
  int totalSeconds;

public:
  TimeSpan(int hours,
           int minutes,
           int seconds)
    : TimeSpan( hours * 3600 +
                minutes * 60 +
                seconds ) { }

  TimeSpan(int seconds)
    : totalSeconds(seconds) { }

  // TODO Implement functionality
};

class TimeSpan {
  int seconds;

public:
  TimeSpan(int hours,
           int minutes,
           int seconds)
    : TimeSpan( hours * 3600 +
                minutes * 60 +
                seconds ) { }

  TimeSpan(int seconds)
    : seconds(seconds) { }

  // TODO Implement functionality
};

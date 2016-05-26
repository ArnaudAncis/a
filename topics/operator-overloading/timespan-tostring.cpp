std::ostream& operator <<(std::ostream& out,
                          const TimeSpan& ts)
{
  out << ts.hours()
      << ":"
      << ts.minutes()
      << ":"
      << ts.seconds();

  return out;
}

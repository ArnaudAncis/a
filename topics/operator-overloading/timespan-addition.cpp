class TimeSpan
{
  // ...
  
  `\NODE{TimeSpan}{return type}` `\NODE{\tt{\bfseries operator} +}{operator}`(`\NODE{\tt\bfseries const}{const parameter}` TimeSpan& other) `\NODE{\tt\bfseries const}{const function}`
  {
    return TimeSpan(totalSeconds +
                    other.totalSeconds);
  }
};

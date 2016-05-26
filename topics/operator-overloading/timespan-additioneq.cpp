class TimeSpan
{
public:
  `\NODE{\tt TimeSpan\&}{return type}` `\NODE{\tt{\bfseries operator} +=}{operator}`(`\NODE{\tt\bfseries const}{const parameter}` TimeSpan& other)`\NODE{\phantom{const}}{nonconst function}`
  {
      totalSeconds += other.totalSeconds;
      return *this;
  }
};

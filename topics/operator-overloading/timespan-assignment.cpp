class TimeSpan
{
  `\NODE{\tt TimeSpan\&}{return type}` `\NODE{\tt{\bfseries operator} =}{operator}`(`\NODE{\tt\bfseries const}{const parameter}` TimeSpan& other)`\NODE{\phantom{const}}{nonconst function}`
  {
    seconds = other.seconds;
    return *this;
  }
};

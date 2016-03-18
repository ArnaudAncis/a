class OilTank
{
  int contents, capacity;

public:
  OilTank(int capacity = 100,
          int contents = 0);

  int getContents()`\only<2->{ \tt\bfseries\color{red} const}`;
  int getCapacity()`\only<3->{ \tt\bfseries\color{red} const}`;
  int getFreeCapacityLeft()`\only<4->{ \tt\bfseries\color{red} const}`;

  void fill(int amount);
  void drain(int amount);
  void transfer(OilTank&, int amount);
};

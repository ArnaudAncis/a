class OilTank
{
private:
  int contents, capacity;

public:
  OilTank(int capacity = 100,
          int contents = 0)
    : contents(contents),
      capacity(capacity) { }
};

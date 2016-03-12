class OilTank
{
private:
  int contents, capacity;

public:
  OilTank() : OilTank(0, 1000) { }

  OilTank(int capacity)
    : OilTank(0, capacity) { }
  
  OilTank(int contents, int capacity)
    : contents(contents),
      capacity(capacity) { }
};

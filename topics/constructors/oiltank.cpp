class OilTank
{
private:
  int contents, capacity;

public:
  OilTank(int capacity)
    : OilTank(0, capacity) { }
  
  OilTank(int contents, int capacity)
    : contents(contents),
      capacity(capacity) { }

  OilTank(const OilTank& other)
    : OilTank(other.contents,
              other.capacity) { }
};

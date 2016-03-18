template<typename T>
class vector
{
private:
  T* items;

public:
  T& operator[](int i);
  const T& operator[](int i) const;
};

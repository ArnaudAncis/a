template<typename T>
class vector
{
private:
  T* contents;

public:
  T& at(int index)
  {
    return contents[index];
  }
};

vector<int> xs;
xs.at(0) = 5;

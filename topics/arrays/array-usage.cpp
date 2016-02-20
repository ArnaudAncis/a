#include <array>

int main() {
  std::array<int, 5> xs = { 1, 2, 3, 4, 5 };

  int total = 0;

  for (int x : xs)
  {
      total += x;
  }
}

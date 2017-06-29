// generate_string_answerbox
#include <iostream>

struct Cell { int value; };

void foo(Cell cell)         { std::cout << "A"; }
void foo(Cell* cell)        { std::cout << "B"; }
void foo(const Cell* cell)  { std::cout << "C"; }

int main() {
  Cell cell;
  Cell* p = &cell;
  const Cell* q = p;
  Cell& r = cell;
  const Cell& s = cell;

  foo(cell);
  foo(&cell);
  foo(p);
  foo(*p);
  foo(q);
  foo(*q);
  foo(r);
  foo(&r);
  foo(s);
  foo(&s);
}

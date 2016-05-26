// generate_associative_answerboxes
#include <iostream>

struct Cell { int value; };

void foo(Cell cell)   { cell.value = 1; }
void foo(Cell* cell)  { cell->value = 2; }
void foo(Cell** cell) { (**cell).value = 3; }

int main() {
  Cell cell;
  Cell* p = &cell;
  
  foo(&cell);
  std::cout << "A:" << cell.value << std::endl;
  foo(cell);
  std::cout << "B:" << cell.value << std::endl;
  foo(p);
  std::cout << "C:" << cell.value << std::endl;
  foo(*p);
  std::cout << "D:" << cell.value << std::endl;
  foo(&p);
  std::cout << "E:" << cell.value << std::endl;
}

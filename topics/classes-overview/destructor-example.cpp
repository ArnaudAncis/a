class MemoryResource {
  int* p;

public:
  MemoryResource() : p( new int[10] ) { }
  ~MemoryResource() { delete[] p; }
};

class Client {
  MemoryResource mr;

  // Does not need destructor
};

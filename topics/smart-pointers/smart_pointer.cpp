template<typename T> class smart_pointer {
  T* p;
public:
  smart_pointer(T* p) : p(p) { }
  ~smart_pointer() { delete p; }

  T* get() { return p; }
};

void foo() {
  smart_pointer<Person> p(new Person);
  // stuff
}

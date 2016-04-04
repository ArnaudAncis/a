template<typename T> class deleter {
  T* p;
public:
  deleter(T* p) : p(p) { }
  ~deleter() { delete p; }
};

void foo() {
  Person* p = new Person("Jorg");
  deleter<Person> pd(p);
  // stuff
}

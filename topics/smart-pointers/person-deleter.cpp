class Person_deleter {
  Person* p;
public:
  Person_deleter(Person* p) : p(p) { }
  ~Person_deleter() { delete p; }
};

void foo() {
  Person* p = new Person("Jorg");
  Person_deleter pd(p);
  // stuff
}

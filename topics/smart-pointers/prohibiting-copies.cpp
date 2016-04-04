void bar(smart_pointer<T> p) { ... }

void foo() {
  smart_pointer<T> p(new T);

  // Should be prohibited
  smart_pointer<T> q = p;

  // Should be prohibited
  bar(p);
}

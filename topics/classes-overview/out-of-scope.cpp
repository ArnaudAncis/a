X foo()
{
  T t;
  U u;
  X x;
  
  // ...

  return x; // t, u, x get destroyed
}

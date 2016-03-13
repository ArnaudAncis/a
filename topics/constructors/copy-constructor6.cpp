Counter foo()
{
  return Counter();
}

// Could call copy
// constructor 2x, 1x, or 0x
Counter c = foo();

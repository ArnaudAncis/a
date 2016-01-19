// Size known at compile-time: ok
int ns[5];

// Size computed at runtime: not ok
int size = foo();
int* ns = new int[size];

// Receives Counter by value
void foo(Counter) { }

// May call copy constructor
// but probably optimised away
foo( Counter() );

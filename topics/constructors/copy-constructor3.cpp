Counter c1;
Counter c2;

// Does NOT call copy constructor
// as no new object is created
// but as existing one is overwritten
// Calls operator =(const Counter&)
c2 = c1;

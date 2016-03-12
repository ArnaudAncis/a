OilTank t1(50, 100);

// Copy constructor is called
OilTank t2 = t1;

// Copy constructor is NOT called
OilTank t3;
t3 = t1;

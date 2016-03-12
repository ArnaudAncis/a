OilTank foo()
{
  return OilTank(100);
}

// Is copy constructor called? `\visible<2->{No!}`
OilTank t = foo();

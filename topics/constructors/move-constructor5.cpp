OilTank foo(const OilTank& t)
{
  return t;
}

OilTank t1;
OilTank t2 = foo(t1);

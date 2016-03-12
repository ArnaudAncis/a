int xs[] = { 0, 0, 0 , 0 };

int& at(int index)
{
  return xs[index];
}

print_array(xs); `\visible<2->{// 0, 0, 0, 0}`

at(0) = 1;

print_array(xs); `\visible<3->{// 1, 0 , 0, 0}`


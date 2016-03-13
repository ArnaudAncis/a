class Foo
{
public:
  Foo(int) { }
};

void bar(Foo) { }

// 1 converted to Foo using constructor
bar(1);

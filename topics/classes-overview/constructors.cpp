class Person
{
private:
  std::string `\NODE{name}{name field}`;
  int `\NODE{age}{age field}`;

public:
  Person(std::string name, int age);
};

Person::Person(std::string `\NODE{name}{name param}`, int `\NODE{age}{age param}`)
  : `\NODE{name}{name field ref}`(`\NODE{name}{name param ref}`), `\NODE{age}{age field ref}`(`\NODE{age}{age param ref}`)
{
}

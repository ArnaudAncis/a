class Person {
  std::string `\pgfmark{constructor field name start}`name`\pgfmark{constructor field name end}`;
  int `\pgfmark{constructor field age start}`age`\pgfmark{constructor field age end}`;

public:
  Person(const std::string&, int);
};

Person::Person(const std::string& `\pgfmark{constructor parameter name start}`name`\pgfmark{constructor parameter name end}`,
               int `\pgfmark{constructor parameter age start}`age`\pgfmark{constructor parameter age end}`)
    : `\pgfmark{constructor initlist name start}`name`\pgfmark{constructor initlist name end}`(`\pgfmark{constructor initlist name value start}`name`\pgfmark{constructor initlist name value end}`),
      `\pgfmark{constructor initlist age start}`age`\pgfmark{constructor initlist age end}`(`\pgfmark{constructor initlist age value start}`age`\pgfmark{constructor initlist age value end}`)
{
}

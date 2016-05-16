#ifndef QUANTITY_H
#define QUANTITY_H

#include <iostream>
#include <string>

class Quantity {
  double amount;
  std::string unit;

public:
  Quantity(double, std::string);
  Quantity(const Quantity&) = default;
  
  double getAmount() const;
  std::string getUnit() const;

  Quantity  operator + (const Quantity&) const;
  Quantity& operator +=(const Quantity&);
};

std::ostream& operator <<(std::ostream&, const Quantity&);

#endif

#include "Quantity.h"

Quantity::Quantity(double amount, std::string unit)
  : amount(amount), unit(unit) { }

double Quantity::getAmount() const {
  return amount;
}

std::string Quantity::getUnit() const {
  return unit;
}

Quantity Quantity::operator +(const Quantity& q) const {
  Quantity copy = *this;
  copy += q;

  return copy;
}

Quantity& Quantity::operator +=(const Quantity& q) {
  if ( unit != q.unit ) {
    abort();
  }
  else {
    amount += q.amount;
  }
}

std::ostream& operator <<(std::ostream& out, const Quantity& q) {
  return out << q.getAmount() << q.getUnit();
}

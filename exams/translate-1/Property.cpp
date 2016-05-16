#include "Property.h"

Property::Property(std::string value) : value(value) { }

std::string Property::read() const
{
  return value;  
}

void Property::write(std::string value)
{
  this->value = value;
}

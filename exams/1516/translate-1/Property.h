#ifndef PROPERTY_H
#define PROPERTY_H

#include "Readable.h"
#include "Writeable.h"
#include <string>

class Property : public Readable, public Writeable
{
  std::string value;

public:
  Property(std::string value = "");
  Property(const Property& p) = default;

  std::string read() const override;
  void write(std::string value) override;
};

#endif

#ifndef READABLE_H
#define READABLE_H

#include <string>

struct Readable {
  virtual std::string read() const = 0;
};

#endif

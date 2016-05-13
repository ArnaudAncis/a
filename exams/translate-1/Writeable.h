#ifndef WRITEABLE_H
#define WRITEABLE_H

#include <string>

struct Writeable {
  virtual void write(std::string) = 0;
};

#endif

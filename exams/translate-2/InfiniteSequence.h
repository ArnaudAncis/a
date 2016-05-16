#ifndef INFINITE_SEQUENCE_H
#define INFINITE_SEQUENCE_H

#include <memory>

class InfiniteSequence {
  std::shared_ptr<InfiniteSequence> m_next;
  int value;

public:
  std::shared_ptr<InfiniteSequence> getNext();
  
  int& value();
  int  value() const;
};

#endif

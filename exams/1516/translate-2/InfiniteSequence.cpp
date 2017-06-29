#include "InfiniteSequence.h"

std::shared_ptr<InfiniteSequence> InfiniteSequence::getNext() {
  if ( m_next == nullptr )
    m_next = std::make_shared<InfiniteSequence>();

  return m_next;
}


int& InfiniteSequence::value() {
  return m_value;
}

int InfiniteSequence::value() const {
  return m_value;
}


#ifndef TESTLIB_H
#define TESTLIB_H

#include "streams/stream.h"
#include <memory>
#include <vector>


#define STREAM(TYPE, ...)  std::make_shared<TestStream<TYPE>>(std::vector<TYPE> { __VA_ARGS__ })


template<typename T>
class TestStream : public Stream<T>
{
    std::vector<T> m_elements;

public:
    TestStream(const std::vector<T>& elements)
        : m_elements(elements) { }

    unsigned size() const override
    {
        return (unsigned) m_elements.size();
    }

    T operator [](unsigned i) const override
    {
        return m_elements[i];
    }
};

#endif

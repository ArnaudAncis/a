#ifndef TESTLIB_H
#define TESTLIB_H

#include "streams/stream.h"
#include "waves/wave.h"
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
        return (unsigned)m_elements.size();
    }

    T operator [](unsigned i) const override
    {
        return m_elements[i];
    }
};

void check_equal_waves(Wave a, Wave b, double dt = 0.05);

Wave constant_wave(double duration, double constant);

Wave linear_wave(double duration, double m, double q);

template<typename T>
void check_equal_streams(std::shared_ptr<Stream<T>> p, std::shared_ptr<Stream<T>> q)
{
    REQUIRE(p->size() == q->size());
    
    auto imax = p->size();
    for (unsigned i = 0; i != imax; ++i)
    {
        CHECK((*p)[i] == (*q)[i]);
    }
}

#endif

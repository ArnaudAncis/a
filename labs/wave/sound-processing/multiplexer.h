#ifndef MULTIPLEXER_H
#define MULTIPLEXER_H

#include "wave.h"
#include <iostream>
#include <memory>


template<typename T>
class Multiplexer : public Stream<T>
{
    std::shared_ptr<Stream<T>> m_left, m_right;

public:
    Multiplexer(std::shared_ptr<Stream<T>> left, std::shared_ptr<Stream<T>> right)
        : m_left(left), m_right(right)
    {
        if (left->size() != right->size())
        {
            std::cerr << "multiplexer requires both streams to have equal size" << std::endl;
            abort();
        }
    }

    unsigned size() const override
    {
        return m_left->size() * 2;
    }

    T operator [](unsigned index) const override
    {
        unsigned i = index / 2;
        
        if (index % 2 == 0)
        {
            return (*m_left)[i];
        }
        else
        {
            return (*m_right)[i];
        }
    }
};

template<typename T>
std::shared_ptr<Stream<T>> multiplex(std::shared_ptr<Stream<T>> left_channel, std::shared_ptr<Stream<T>> right_channel)
{
    return std::make_shared<Multiplexer<T>>(left_channel, right_channel);
}

#endif

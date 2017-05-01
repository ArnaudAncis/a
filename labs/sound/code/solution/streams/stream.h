#ifndef STREAM_H
#define STREAM_H

template<typename T>
class Stream
{
public:
    virtual unsigned size() const = 0;
    virtual T operator [](unsigned) const = 0;
};

#endif

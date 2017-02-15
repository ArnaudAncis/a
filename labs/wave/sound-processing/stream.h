#ifndef STREAM_H
#define STREAM_H

class Stream
{
public:
    virtual unsigned size() const = 0;
    virtual double operator [](unsigned) const = 0;
};

#endif

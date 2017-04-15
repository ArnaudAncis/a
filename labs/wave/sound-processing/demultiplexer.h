#ifndef DEMULTIPLAYER_H
#define DEMULTIPLAYER_H

#include "stream.h"
#include <memory>
#include <vector>


class Demultiplexer
{
private:
    std::shared_ptr<Stream<double>> m_left_channel;
    std::shared_ptr<Stream<double>> m_right_channel;

public:
    Demultiplexer(std::shared_ptr<Stream<double>>);

    std::shared_ptr<Stream<double>> left_channel() const;
    std::shared_ptr<Stream<double>> right_channel() const;
};

#endif

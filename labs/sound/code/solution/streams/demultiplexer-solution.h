#ifndef DEMULTIPLAYER_H
#define DEMULTIPLAYER_H

#include "streams/stream.h"
#include <memory>
#include <vector>


namespace solution
{
    template<typename T>
    class ChannelStream : public Stream<T>
    {
        std::shared_ptr<Stream<T>> m_stream;
        unsigned m_offset;

    public:
        ChannelStream(std::shared_ptr<Stream<T>> stream, unsigned offset)
            : m_stream(stream), m_offset(offset) { }

        unsigned size() const { return m_stream->size() / 2; }
        T operator [](unsigned index) const { return (*m_stream)[2 * index + m_offset]; }
    };

    template<typename T>
    struct Demultiplexer
    {
        std::shared_ptr<Stream<T>> left_channel, right_channel;

        Demultiplexer(std::shared_ptr<Stream<T>> stream)
            : left_channel(std::make_shared<ChannelStream<T>>(stream, 0)), right_channel(std::make_shared<ChannelStream<T>>(stream, 1)) { }
    };
}

#endif

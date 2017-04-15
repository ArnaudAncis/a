#include "demultiplexer.h"


namespace
{
    class ChannelStream : public Stream<double>
    {
    private:
        std::shared_ptr<Stream<double>> m_stream;
        unsigned m_offset;

    public:
        ChannelStream(std::shared_ptr<Stream<double>> stream, unsigned offset)
            : m_stream(stream), m_offset(offset) { }

        unsigned size() const { return m_stream->size() / 2; }
        double operator [](unsigned index) const { return (*m_stream)[2 * index + m_offset]; }
    };
}


Demultiplexer::Demultiplexer(std::shared_ptr<Stream<double>> stream)
    : m_left_channel(std::make_shared<ChannelStream>(stream, 0)), m_right_channel(std::make_shared<ChannelStream>(stream, 1))
{
    // NOP
}

std::shared_ptr<Stream<double>> Demultiplexer::left_channel() const
{
    return m_left_channel;
}

std::shared_ptr<Stream<double>> Demultiplexer::right_channel() const
{
    return m_right_channel;
}

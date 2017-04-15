#include "int16-stream-splitter.h"


namespace
{
    class Int16StreamSplitter : public Stream<uint8_t>
    {
        std::shared_ptr<Stream<int16_t>> m_stream;

    public:
        Int16StreamSplitter(std::shared_ptr<Stream<int16_t>> stream)
            : m_stream(stream) { }

        unsigned size() const override
        {
            return m_stream->size() * 2;
        }

        uint8_t operator [](unsigned index) const override
        {
            unsigned i = index / 2;
            int16_t item = (*m_stream)[i];
            uint16_t& unsigned_item = *reinterpret_cast<uint16_t*>(&item);
            uint8_t lower = unsigned_item & 0xFF;
            uint8_t upper = unsigned_item >> 8;

            return index % 2 == 0 ? lower : upper;
        }
    };
}

std::shared_ptr<Stream<uint8_t>> convert_int16_to_uint8_stream(std::shared_ptr<Stream<int16_t>> stream)
{
    return std::make_shared<Int16StreamSplitter>(stream);
}

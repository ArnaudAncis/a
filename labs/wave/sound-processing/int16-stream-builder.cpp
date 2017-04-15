#include "int16-stream-builder.h"


namespace
{
    class Int16StreamBuilder : public Stream<int16_t>
    {
        std::shared_ptr<Stream<uint8_t>> m_stream;

    public:
        Int16StreamBuilder(std::shared_ptr<Stream<uint8_t>> stream)
            : m_stream(stream) { }

        unsigned size() const override
        {
            return m_stream->size() / 2;
        }

        int16_t operator [](unsigned index) const override
        {
            uint8_t lower = (*m_stream)[2 * index];
            uint8_t upper = (*m_stream)[2 * index + 1];
            uint16_t unsigned_combined = (upper << 8) | lower;
            int16_t& signed_combined = *reinterpret_cast<int16_t*>(&unsigned_combined);

            return signed_combined;
        }
    };
}

std::shared_ptr<Stream<int16_t>> convert_uint8_to_int16_stream(std::shared_ptr<Stream<uint8_t>> stream)
{
    return std::make_shared<Int16StreamBuilder>(stream);
}

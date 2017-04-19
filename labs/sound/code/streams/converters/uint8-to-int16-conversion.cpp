#include "streams/converters/uint8-to-int16-conversion.h"
#include <assert.h>


namespace
{
    class Uint8ToInt16Converter : public Stream<int16_t>
    {
        std::shared_ptr<Stream<uint8_t>> m_stream;

    public:
        Uint8ToInt16Converter(std::shared_ptr<Stream<uint8_t>> stream)
            : m_stream(stream) { }

        unsigned size() const override
        {
            return m_stream->size() / 2;
        }

        int16_t operator [](unsigned index) const override
        {
            auto lower = (*m_stream)[2 * index];
            auto upper = (*m_stream)[2 * index + 1];
            uint16_t combined = lower | (upper << 8);
            int16_t& result = *(reinterpret_cast<int16_t*>(&combined));

            return result;
        }
    };
}

std::shared_ptr<Stream<int16_t>> convert_uint8_to_int16_stream(std::shared_ptr<Stream<uint8_t>> stream)
{
    return std::make_shared<Uint8ToInt16Converter>(stream);
}

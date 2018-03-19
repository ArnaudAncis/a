#include "streams/converters/double-to-uint8-conversion.h"
#include <assert.h>


namespace
{
    class DoubleToUint8Converter : public Stream<uint8_t>
    {
        std::shared_ptr<Stream<double>> m_stream;

    public:
        DoubleToUint8Converter(std::shared_ptr<Stream<double>> stream)
            : m_stream(stream) { }

        unsigned size() const override
        {
            return m_stream->size();
        }

        uint8_t operator [](unsigned index) const override
        {
            double value = (*m_stream)[index];

            assert(-1 <= value);
            assert(value <= 1);

            return (uint8_t)((*m_stream)[index] * 127.5 + 127.5);
        }
    };
}

std::shared_ptr<Stream<uint8_t>> convert_double_to_uint8_stream(std::shared_ptr<Stream<double>> stream)
{
    return std::make_shared<DoubleToUint8Converter>(stream);
}

#include "streams/converters/uint8-to-double-conversion.h"
#include <assert.h>


namespace
{
    class Uint8ToDoubleConverter : public Stream<double>
    {
        std::shared_ptr<Stream<uint8_t>> m_stream;

    public:
        Uint8ToDoubleConverter(std::shared_ptr<Stream<uint8_t>> stream)
            : m_stream(stream) { }

        unsigned size() const override
        {
            return m_stream->size();
        }

        double operator [](unsigned index) const override
        {
            return (*m_stream)[index] / 127.5 - 1;
        }
    };
}

std::shared_ptr<Stream<double>> convert_uint8_to_double_stream(std::shared_ptr<Stream<uint8_t>> stream)
{
    return std::make_shared<Uint8ToDoubleConverter>(stream);
}

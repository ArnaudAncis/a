#include "streams/converters/int16-to-double-conversion.h"
#include <assert.h>


namespace
{
    class Int16ToDoubleConverter : public Stream<double>
    {
        std::shared_ptr<Stream<int16_t>> m_stream;

    public:
        Int16ToDoubleConverter(std::shared_ptr<Stream<int16_t>> stream)
            : m_stream(stream) { }

        unsigned size() const override
        {
            return m_stream->size();
        }

        double operator [](unsigned index) const override
        {
            return (1 + 2 * (*m_stream)[index]) / 65535.0;
        }
    };
}

std::shared_ptr<Stream<double>> convert_int16_to_double_stream(std::shared_ptr<Stream<int16_t>> stream)
{
    return std::make_shared<Int16ToDoubleConverter>(stream);
}

#include "double-to-int16-converter.h"


namespace
{
    class DoubleToInt16Converter : public Stream<int16_t>
    {
        std::shared_ptr<Stream<double>> m_stream;

    public:
        DoubleToInt16Converter(std::shared_ptr<Stream<double>> stream)
            : m_stream(stream) { }

        unsigned size() const override
        {
            return m_stream->size(); 
        }

        int16_t operator [](unsigned index) const override
        {
            return (int16_t)((*m_stream)[index] * 32767);
        }
    };
}

std::shared_ptr<Stream<int16_t>> convert_double_to_int16_stream(std::shared_ptr<Stream<double>> stream)
{
    return std::make_shared<DoubleToInt16Converter>(stream);
}

#include "conversions.h"
#include <assert.h>


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
            double value = (*m_stream)[index];

            assert(-1 <= value);
            assert(value <= 1);

            return (int16_t)((*m_stream)[index] * 32767);
        }
    };

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
            uint8_t lower = (*m_stream)[2 * index];
            uint8_t upper = (*m_stream)[2 * index + 1];
            uint16_t unsigned_combined = (upper << 8) | lower;
            int16_t& signed_combined = *reinterpret_cast<int16_t*>(&unsigned_combined);

            return signed_combined;
        }
    };

    class Int16ToUint8Converter: public Stream<uint8_t>
    {
        std::shared_ptr<Stream<int16_t>> m_stream;

    public:
        Int16ToUint8Converter(std::shared_ptr<Stream<int16_t>> stream)
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

std::shared_ptr<Stream<int16_t>> convert_double_to_int16_stream(std::shared_ptr<Stream<double>> stream)
{
    return std::make_shared<DoubleToInt16Converter>(stream);
}

std::shared_ptr<Stream<int16_t>> convert_uint8_to_int16_stream(std::shared_ptr<Stream<uint8_t>> stream)
{
    return std::make_shared<Uint8ToInt16Converter>(stream);
}

std::shared_ptr<Stream<uint8_t>> convert_int16_to_uint8_stream(std::shared_ptr<Stream<int16_t>> stream)
{
    return std::make_shared<Int16ToUint8Converter>(stream);
}


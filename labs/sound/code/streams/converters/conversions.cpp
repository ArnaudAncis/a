#include "streams/converters/conversions.h"
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
            uint8_t lower = (*m_stream)[2 * index];
            uint8_t upper = (*m_stream)[2 * index + 1];
            uint16_t unsigned_combined = (upper << 8) | lower;
            int16_t& signed_combined = *reinterpret_cast<int16_t*>(&unsigned_combined);

            return signed_combined;
        }
    };

    class Int16ToUint8Converter : public Stream<uint8_t>
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


std::shared_ptr<Stream<int16_t>> convert_uint8_to_int16_stream(std::shared_ptr<Stream<uint8_t>> stream)
{
    return std::make_shared<Uint8ToInt16Converter>(stream);
}

std::shared_ptr<Stream<uint8_t>> convert_int16_to_uint8_stream(std::shared_ptr<Stream<int16_t>> stream)
{
    return std::make_shared<Int16ToUint8Converter>(stream);
}



std::shared_ptr<Stream<double>> convert_uint8_to_double_stream(std::shared_ptr<Stream<uint8_t>> stream)
{
    return std::make_shared<Uint8ToDoubleConverter>(stream);
}



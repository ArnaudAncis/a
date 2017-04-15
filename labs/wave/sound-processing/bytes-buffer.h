#ifndef BUFFER_H
#define BUFFER_H

#include <stdexcept>
#include <assert.h>
#include <memory>
#include <string>


// Define type alias for uint8_t
// byte and uint8_t are now equivalent
typedef uint8_t byte;


template<typename T>
class BufferInterpretation
{
private:
    std::shared_ptr<byte> m_data;
    unsigned m_start;

public:
    BufferInterpretation(std::shared_ptr<byte> data, unsigned start)
        : m_data(data), m_start(start) { }

    const T* operator ->() const { return reinterpret_cast<const T*>(m_data.get() + m_start); }
    T operator *() const { return *reinterpret_cast<const T*>(m_data.get() + m_start); }
};


class BytesBuffer
{
private:
    std::shared_ptr<byte> m_data;
    unsigned m_start, m_size;

public:
    BytesBuffer(unsigned size)
        : m_data(new byte[(unsigned)size], std::default_delete<byte[]>()), m_start(0), m_size(size) { }

    BytesBuffer(std::shared_ptr<byte> data, unsigned size, unsigned start = 0)
        : m_data(data), m_start(start), m_size(size) { }

    template<typename T>
    BufferInterpretation<T> reinterpret() const
    {
        if (sizeof(T) > m_size)
        {
            throw std::runtime_error("object does not fit in buffer");
        }
        else
        {
            return BufferInterpretation<T>(m_data, m_start);
        }
    }

    BytesBuffer slice(unsigned start, unsigned size) const;
    BytesBuffer slice(unsigned start) const;

    unsigned size() const { return m_size; }

    byte* data() { return m_data.get() + m_start; }
    const byte* data() const { return m_data.get() + m_start; }

    byte& operator [](unsigned index);
    byte operator [](unsigned index) const;

    BytesBuffer& operator=(const BytesBuffer&) = default;
};

BytesBuffer read_buffer_from_file(const std::string&);

#endif

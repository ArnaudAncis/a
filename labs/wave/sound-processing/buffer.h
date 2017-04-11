#ifndef BUFFER_H
#define BUFFER_H

#include <stdexcept>
#include <assert.h>
#include <memory>
#include <string>


template<typename T>
class BufferInterpretation
{
private:
    std::shared_ptr<uint8_t> m_data;
    unsigned m_start;

public:
    BufferInterpretation(std::shared_ptr<uint8_t> data, unsigned start)
        : m_data(data), m_start(start) { }

    const T* operator ->() const { return reinterpret_cast<const T*>(m_data.get() + m_start); }
    T operator *() const { return *reinterpret_cast<const T*>(m_data.get() + m_start); }
};


class Buffer
{
private:
    std::shared_ptr<uint8_t> m_data;
    unsigned m_start, m_size;

public:
    Buffer(std::shared_ptr<uint8_t> data, unsigned size, unsigned start = 0)
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

    Buffer slice(unsigned start, unsigned size) const;
    Buffer slice(unsigned start) const;

    unsigned size() const { return m_size; }
    const uint8_t* data() { return m_data.get() + m_start; }

    uint8_t operator [](unsigned index) const;
};

Buffer read_buffer_from_file(const std::string&);

#endif

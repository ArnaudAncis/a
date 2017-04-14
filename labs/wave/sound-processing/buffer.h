#ifndef BUFFER_H
#define BUFFER_H

#include <memory>


//class Buffer
//{
//private:
//    std::shared_ptr<uint8_t> m_data;
//    unsigned m_start, m_size;
//
//public:
//    Buffer(std::shared_ptr<uint8_t> data, unsigned start, unsigned size)
//        : m_data(data), m_start(start), m_size(size) { }
//
//    template<typename T>
//    const T* reinterpret() const
//    {
//        return reinterpret_cast<const T*>(m_data.get() + m_start);
//    }
//
//    Buffer slice(unsigned start, unsigned size)
//    {
//        return Buffer(m_data, m_start + start, size);
//    }
//
//    const buffer slice(unsigned start, unsigned size) const
//    {
//        return buffer(m_data, m_start + start, size);
//    }
//};

class BufferInterals;

class Buffer
{
private:
    std::shared_ptr<BufferInterals> m_internals;
    
public:
    Buffer(unsigned size);
    ~Buffer();

};

#endif

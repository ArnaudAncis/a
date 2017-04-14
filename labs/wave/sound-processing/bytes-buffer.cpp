#include "bytes-buffer.h"
#include <fstream>


BytesBuffer BytesBuffer::slice(unsigned start, unsigned size) const
{
    if (start + size > this->m_size)
    {
        throw std::runtime_error("illegal slice");
    }
    else
    {
        return BytesBuffer(m_data, size, m_start + start);
    }
}

BytesBuffer BytesBuffer::slice(unsigned start) const
{
    return slice(start, m_size - start);
}

BytesBuffer read_buffer_from_file(const std::string& path)
{
    // Open file in binary mode, start at end position
    std::ifstream in(path, std::ios::binary | std::ios::ate);

    // Get size of file
    unsigned size = (unsigned) in.tellg();

    // Seek to start of file
    in.seekg(0, std::ios::beg);

    // Create buffer
    BytesBuffer buffer(size);

    // Read file
    in.read(reinterpret_cast<char*>(buffer.data()), size);

    // Return buffer
    return buffer;
}

byte& BytesBuffer::operator [](unsigned index)
{
    if (index >= m_size)
    {
        throw std::runtime_error("index out of bounds");
    }
    else
    {
        return m_data.get()[m_start + index];
    }
}

byte BytesBuffer::operator [](unsigned index) const
{
    if (index >= m_size)
    {
        throw std::runtime_error("index out of bounds");
    }
    else
    {
        return m_data.get()[m_start + index];
    }
}

//BytesBuffer& BytesBuffer::operator =(const BytesBuffer& buffer)
//{
//    this->m_data = buffer.m_data;
//    this->m_size = buffer.m_size;
//    this->m_start = buffer.m_start;
//
//    return *this;
//}

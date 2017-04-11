#include "buffer.h"
#include <fstream>


Buffer Buffer::slice(unsigned start, unsigned size) const
{
    if (start + size > this->m_size)
    {
        throw std::runtime_error("illegal slice");
    }
    else
    {
        return Buffer(m_data, size, m_start + start);
    }
}

Buffer Buffer::slice(unsigned start) const
{
    return slice(start, m_size - start);
}

Buffer read_buffer_from_file(const std::string& path)
{
    // Open file in binary mode, start at end position
    std::ifstream in(path, std::ios::binary | std::ios::ate);

    // Get size of file
    auto size = in.tellg();

    // Seek to start of file
    in.seekg(0, std::ios::beg);

    // Create buffer
    std::shared_ptr<uint8_t> bytes(new uint8_t[(unsigned)size], std::default_delete<uint8_t[]>());

    // Read file
    in.read(reinterpret_cast<char*>(bytes.get()), size);

    // Return buffer
    return Buffer(bytes, (unsigned) size);
}

uint8_t Buffer::operator [](unsigned index) const
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
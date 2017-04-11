#include "wave-file.h"
#include "buffer.h"
#include <fstream>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>


namespace
{
#pragma pack(push, 1)

    struct CHUNK_HEADER
    {
        uint32_t chunk_id;
        uint32_t chunk_size;
    };

    struct RIFF_CHUNK
    {
        CHUNK_HEADER header;
        uint32_t format;
    };

    struct FMT_CHUNK
    {
        CHUNK_HEADER header;
        uint16_t audio_format;
        uint16_t channels;
        uint32_t sample_rate;
        uint32_t byte_rate;
        uint16_t block_align;
        uint16_t bits_per_sample;
    };

#pragma pack(pop)

    const unsigned RIFF_CHUNK_ID = 0x46464952;
    const unsigned FMT_CHUNK_ID = 0x20746d66;
    const unsigned DATA_CHUNK_ID = 0x61746164;


    std::vector<Buffer> find_chunks(Buffer buffer)
    {
        std::vector<Buffer> chunks;

        while (buffer.size() > 0)
        {
            auto header = buffer.template reinterpret<CHUNK_HEADER>();

            unsigned size = header->chunk_size + sizeof(CHUNK_HEADER);
            unsigned rounded_size = size % 2 == 0 ? size : size + 1; // Chunk is padded so that it contains an even amount of bytes
            chunks.push_back(buffer.slice(0, size));
            buffer = buffer.slice(rounded_size);
        }

        return chunks;
    }

    BufferInterpretation<FMT_CHUNK> find_fmt_chunk(const std::vector<Buffer>& chunks)
    {
        for (auto& chunk : chunks)
        {
            auto header = chunk.reinterpret<CHUNK_HEADER>();
            
            if (header->chunk_id == FMT_CHUNK_ID)
            {
                return chunk.reinterpret<FMT_CHUNK>();
            }
        }

        throw std::runtime_error("no fmt chunk found");
    }

    Buffer find_data(const std::vector<Buffer>& chunks)
    {
        for (auto& chunk : chunks)
        {
            auto header = chunk.reinterpret<CHUNK_HEADER>();

            if (header->chunk_id == DATA_CHUNK_ID)
            {
                return chunk.slice(sizeof(CHUNK_HEADER));
            }
        }

        throw std::runtime_error("no data chunk found");
    }
}


void read_wave_file(const std::string& filename)
{
    auto buffer = read_buffer_from_file(filename);
    auto riff = buffer.template reinterpret<RIFF_CHUNK>();

    if (riff->header.chunk_id != RIFF_CHUNK_ID)
    {
        throw std::runtime_error("invalid wav file");
    }

    // Skip RIFF chunk descriptor
    buffer = buffer.slice(sizeof(RIFF_CHUNK), riff->header.chunk_size - 4);

    // Find chunks
    auto chunks = find_chunks(buffer);

    auto fmt_chunk = find_fmt_chunk(chunks);
    auto data = find_data(chunks);

    auto fmt = *fmt_chunk;
}


void write_wave(const std::string& filename, const uint8_t* buffer, unsigned size)
{
    //std::ofstream out(filename, std::ios::binary);

    //RIFF_CHUNK riff{ chunk_id<RIFF_CHUNK>(), 4 + sizeof(FMT_CHUNK) + sizeof(DATA_CHUNK) + size, 0x45564157 };
    //out.write(reinterpret_cast<const char*>(&riff), sizeof(RIFF_CHUNK));

    //FMT_CHUNK fmt{ chunk_id<FMT_CHUNK>(), sizeof(FMT_CHUNK) - 8, 1, 1, 44100, 44100, 1, 8 };
    //out.write(reinterpret_cast<const char*>(&fmt), sizeof(FMT_CHUNK));

    //DATA_CHUNK data{ chunk_id<DATA_CHUNK>(), size };
    //out.write(reinterpret_cast<const char*>(&data), sizeof(DATA_CHUNK));

    //out.write(reinterpret_cast<const char*>(buffer), size);
}
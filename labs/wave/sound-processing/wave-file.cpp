#include "wave-file.h"
#include "bytes-buffer.h"
#include "data-stream.h"
#include <iostream>
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


    std::vector<BytesBuffer> find_chunks(BytesBuffer buffer)
    {
        std::vector<BytesBuffer> chunks;

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

    BufferInterpretation<FMT_CHUNK> find_fmt_chunk(const std::vector<BytesBuffer>& chunks)
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

    BytesBuffer find_data(const std::vector<BytesBuffer>& chunks)
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

void read_wave_file(const std::string& filename, WAVE_DATA* wave_data)
{
    auto buffer = read_buffer_from_file(filename);
    auto riff = buffer.template reinterpret<RIFF_CHUNK>();
    auto f = *riff;

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

    // Fill in wave data
    wave_data->bits_per_sample = fmt_chunk->bits_per_sample;
    wave_data->n_channels = fmt_chunk->channels;
    wave_data->sample_rate = fmt_chunk->sample_rate;
    wave_data->stream = std::make_shared<DataStream>(data);
}

void write_wave_file(const std::string& filename, const WAVE_DATA& wave_data)
{
    std::ofstream out(filename, std::ios::binary);
    
    if (!out)
    {
        std::cerr << "Could not open " << filename << " for writing" << std::endl;
        abort();
    }

    RIFF_CHUNK riff;
    riff.header.chunk_id = RIFF_CHUNK_ID;
    riff.header.chunk_size = 4 + sizeof(FMT_CHUNK) + sizeof(CHUNK_HEADER) + wave_data.stream->size();
    riff.format = 0x45564157;
    out.write(reinterpret_cast<const char*>(&riff), sizeof(RIFF_CHUNK));

    FMT_CHUNK fmt;
    fmt.header.chunk_id = FMT_CHUNK_ID;
    fmt.header.chunk_size = sizeof(FMT_CHUNK) - 8;
    fmt.audio_format = 1;
    fmt.channels = wave_data.n_channels;
    fmt.sample_rate = wave_data.sample_rate;
    fmt.byte_rate = wave_data.n_channels * wave_data.sample_rate * wave_data.bits_per_sample / 8;
    fmt.block_align = wave_data.n_channels * wave_data.bits_per_sample / 8;
    fmt.bits_per_sample = (uint16_t)wave_data.bits_per_sample;
    out.write(reinterpret_cast<const char*>(&fmt), sizeof(FMT_CHUNK));

    CHUNK_HEADER data;
    data.chunk_id = DATA_CHUNK_ID;
    data.chunk_size = wave_data.stream->size();
    out.write(reinterpret_cast<const char*>(&data), sizeof(CHUNK_HEADER));

    std::unique_ptr<uint8_t[]> buffer(new uint8_t[wave_data.stream->size()]);
    for (unsigned i = 0; i != wave_data.stream->size(); ++i)
    {
        buffer[i] = (*wave_data.stream)[i];
    }
    out.write(reinterpret_cast<const char*>(buffer.get()), wave_data.stream->size());
}

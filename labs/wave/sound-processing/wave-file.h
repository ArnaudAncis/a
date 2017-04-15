#ifndef WAV_FILE_H
#define WAV_FILE_H

#include "streams/stream.h"
#include <memory>
#include <cstdint>
#include <string>


struct WAVE_DATA
{
    unsigned bits_per_sample;
    unsigned n_channels;
    unsigned sample_rate;
    std::shared_ptr<Stream<uint8_t>> stream;
};

void read_wave_file(const std::string& filename, WAVE_DATA*);
void write_wave_file(const std::string&, const WAVE_DATA&);

#endif

#ifndef WAV_FILE_H
#define WAV_FILE_H

#include "bytes-buffer.h"
#include <memory>
#include <cstdint>
#include <string>


struct WAVE_DATA
{
    unsigned bits_per_sample;
    unsigned n_channels;
    unsigned sample_rate;
    BytesBuffer bytes;
};

void read_wave_file(const std::string& filename);
void write_wave_file(const std::string&, const WAVE_DATA&);

#endif

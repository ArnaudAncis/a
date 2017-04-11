#ifndef WAV_FILE_H
#define WAV_FILE_H

#include <memory>
#include <cstdint>
#include <string>


void read_wave_file(const std::string& filename);
void write_wave(const std::string& filename, const uint8_t* buffer, unsigned size);

#endif

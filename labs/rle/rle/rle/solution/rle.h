#ifndef RLE_H
#define RLE_H

#include <vector>

std::vector<uint8_t> rle(uint8_t* input, unsigned size);
std::vector<uint8_t> unrle(uint8_t* input, unsigned size);

#endif
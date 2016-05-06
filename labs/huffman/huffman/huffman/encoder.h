#ifndef ENCODER_H
#define ENCODER_H

#include "huffman_tree.h"
#include "bit_sequence.h"
#include <map>
#include <vector>

class encoder
{
	std::map<uint8_t, bit_sequence> map;
	bit_sequence eof;

	void gather_data(const huffman_tree& tree, const bit_sequence& prefix);

public:
	encoder(const huffman_tree& tree);

};

#endif
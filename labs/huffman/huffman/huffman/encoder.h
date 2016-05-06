#ifndef ENCODER_H
#define ENCODER_H

#include "huffman_tree.h"
#include "bit_sequence.h"
#include <map>
#include <vector>

class encoder
{
	std::map<uint8_t, bit_sequence> m_map;
	bit_sequence m_eof;

	void gather_data(const huffman_tree& tree, const bit_sequence& prefix);

public:
	encoder(const huffman_tree& tree);

	bit_sequence operator[](uint8_t x) const { return m_map.at(x); }
	bit_sequence eof() const { return m_eof; }
};

#endif
#ifndef DECODER_H
#define DECODER_H

#include "huffman_tree.h"
#include "bit_sequence.h"
#include <memory>

class decoder
{
	std::shared_ptr<const huffman_tree> root;

public:
	decoder(std::shared_ptr<const huffman_tree> root) : root(root) { }

	std::string decode(const bit_sequence& bits) const;
};

#endif
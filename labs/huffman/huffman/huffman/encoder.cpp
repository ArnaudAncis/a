#include "encoder.h"

void encoder::gather_data(const huffman_tree& tree, const bit_sequence& prefix)
{
	{
		auto p = dynamic_cast<const branch*>(&tree);

		if (p != nullptr)
		{
			gather_data(*(p->left()), prefix + bit_sequence::zero());
			gather_data(*(p->right()), prefix + bit_sequence::one());

			return;
		}
	}

	{
		auto p = dynamic_cast<const datum_leaf*>(&tree);

		if (p != nullptr)
		{
			map.insert(std::pair<uint8_t, bit_sequence>(p->datum(), prefix));

			return;
		}
	}

	{
		auto p = dynamic_cast<const eof_leaf*>(&tree);

		eof = prefix;
	}
}

encoder::encoder(const huffman_tree& tree)
	: eof( bit_sequence::empty() )
{
	gather_data(tree, bit_sequence::empty());
}
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
		auto p = dynamic_cast<const leaf*>(&tree);

		if (p != nullptr)
		{
			m_map.insert(std::pair<uint8_t, bit_sequence>(p->datum(), prefix));

			return;
		}
	}
}

encoder::encoder(const huffman_tree& tree)
{
	gather_data(tree, bit_sequence::empty());
}

bit_sequence encoder::operator[](std::string string) const
{
	auto result = bit_sequence::empty();

	for (char c : string)
	{
		result += (*this)[uint8_t(c)];
	}

	return result;
}
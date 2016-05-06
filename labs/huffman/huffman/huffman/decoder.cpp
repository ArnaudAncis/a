#include "decoder.h"

std::string decoder::decode(const bit_sequence& bits) const
{
	std::string result;
	auto p = std::dynamic_pointer_cast<const branch>(this->root);

	for (unsigned i = 0; i != bits.length(); ++i)
	{
		auto q = bits[i] ? p->right() : p->left();

		std::shared_ptr<const leaf> lf = std::dynamic_pointer_cast<const leaf>(q);

		if (lf != nullptr)
		{
			result += lf->datum();
		}
		else
		{
			p = std::dynamic_pointer_cast<const branch>(q);
		}
	}

	return result;
}
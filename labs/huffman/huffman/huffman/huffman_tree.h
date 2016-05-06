#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include "frequency_map.h"
#include <cstdint>
#include <memory>

class huffman_tree
{
protected:
	unsigned m_weight;

	huffman_tree(unsigned weight) : m_weight(weight) { }

public:
	virtual ~huffman_tree() { }

	unsigned weight() const { return m_weight; }
};

class leaf : public huffman_tree
{
protected:
	leaf(unsigned weight) : huffman_tree(weight) { }
};

class datum_leaf : public leaf
{
private:
	uint8_t m_datum;

public:
	datum_leaf(unsigned weight, uint8_t datum) : leaf(weight), m_datum(datum) { }

	uint8_t datum() const { return m_datum; }
};

class eof_leaf : public leaf
{
public:
	eof_leaf() : leaf(1) { }
};

class branch : public huffman_tree
{
private:
	std::shared_ptr<huffman_tree> m_left;
	std::shared_ptr<huffman_tree> m_right;

public:
	branch(std::shared_ptr<huffman_tree> left, std::shared_ptr<huffman_tree> right)
		: huffman_tree(left->weight() + right->weight()), m_left(left), m_right(right) { }

	std::shared_ptr<const huffman_tree> left() const { return m_left; };
	std::shared_ptr<const huffman_tree> right() const { return m_right; };

};

std::shared_ptr<huffman_tree> build_tree(const frequency_map&);

#endif

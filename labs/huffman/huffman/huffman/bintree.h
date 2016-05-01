#ifndef BINTREE_H
#define BINTREE_H

#include "frequency_map.h"
#include <cstdint>
#include <memory>

class bintree
{
protected:
	unsigned m_weight;

	bintree(unsigned weight) : m_weight(weight) { }

public:
	virtual ~bintree() { }

	unsigned weight() const { return m_weight; }
};

class leaf : public bintree
{
protected:
	leaf(unsigned weight) : bintree(weight) { }
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
	eof_leaf() : leaf(0) { }
};

class branch : public bintree
{
private:
	std::shared_ptr<bintree> m_left;
	std::shared_ptr<bintree> m_right;

public:
	branch(std::shared_ptr<bintree> left, std::shared_ptr<bintree> right)
		: bintree(left->weight() + right->weight()), m_left(left), m_right(right) { }

	std::shared_ptr<bintree> left() { return m_left; };
	std::shared_ptr<bintree> right() { return m_right; };

};

std::shared_ptr<bintree> build_tree(const frequency_map&);

#endif

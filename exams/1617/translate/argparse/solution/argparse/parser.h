#ifndef PARSER_H
#define PARSER_H

#include "parameter.h"
#include <vector>
#include <memory>


class Parser
{
private:
	std::vector<std::shared_ptr<Parameter>> m_parameters;

	bool process(std::list<std::string>&) const;

public:
	Parser& add_parameter(std::shared_ptr<Parameter> parameter);

	void parse(std::list<std::string>&) const;
};

#endif

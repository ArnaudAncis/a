#include "parser.h"


Parser& Parser::add_parameter(std::shared_ptr<Parameter> parameter)
{
	m_parameters.push_back(parameter);

	return *this;
}

bool Parser::process(std::list<std::string>& arguments) const
{
	for (auto& parameter : m_parameters)
	{
		if (parameter->parse(arguments))
		{
			return true;
		}
	}

	return false;
}

void Parser::parse(std::list<std::string>& arguments) const
{
	std::list<std::string> positional;

	while (!arguments.empty())
	{
		if (!process(arguments))
		{
			positional.push_back(arguments.front());
			arguments.pop_front();
		}
	}

	arguments = positional;
}

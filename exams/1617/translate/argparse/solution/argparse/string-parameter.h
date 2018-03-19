#ifndef STRING_PARAMETER_H
#define STRING_PARAMETER_H

#include "parameter.h"
#include <string>
#include <memory>


class StringParameter : public Parameter
{
	std::string m_value;

public:
	StringParameter(const std::string& name, const std::string& default_value);

	bool parse(std::list<std::string>& args) override;

    /*
      Return type must be string. string& would give access to the internal data member,
      which we do not want. Do not forget const: asking a StringParameter's value
      does not change the StringParameter.
    */
	std::string value() const;
};

std::shared_ptr<StringParameter> string(const std::string& name, const std::string& default_value);

#endif

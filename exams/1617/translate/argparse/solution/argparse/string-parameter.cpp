#include "string-parameter.h"


StringParameter::StringParameter(const std::string& name, const std::string& default_value)
	: Parameter(name), m_value(default_value) { }

bool StringParameter::parse(std::list<std::string>& args)
{
	if (!args.size() >= 2 && args.front() == "--" + m_name)
	{
		args.pop_front();
		m_value = args.front();
		args.pop_front();

		return true;
	}
	else
	{
		return false;
	}
}

std::string StringParameter::value() const
{
	return m_value;
}

std::shared_ptr<StringParameter> string(const std::string& name, const std::string& default_value)
{
	return std::make_shared<StringParameter>(name, default_value);
}

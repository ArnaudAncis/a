#include "flag-parameter.h"


FlagParameter::FlagParameter(const std::string& name)
	: Parameter(name), m_set(false) { }

bool FlagParameter::parse(std::list<std::string>& args)
{
	if (!args.empty() && args.front() == "--" + m_name)
	{
		args.pop_front();
		m_set = true;

		return true;
	}
	else
	{
		return false;
	}
}

bool FlagParameter::is_set() const
{
	return m_set;
}

std::shared_ptr<FlagParameter> flag(const std::string& name)
{
	return std::make_shared<FlagParameter>(name);
}

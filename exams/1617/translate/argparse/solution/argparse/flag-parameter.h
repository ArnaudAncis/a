#ifndef FLAG_PARAMETER_H
#define FLAG_PARAMETER_H

#include "parameter.h"
#include <memory>


class FlagParameter : public Parameter // Do not forget public!
{
	bool m_set;

public:
	FlagParameter(const std::string& name);

	bool parse(std::list<std::string>& args) override;

    /*
      Do not forget const. Using is_set does not change the FlagParameter.
    */
    bool is_set() const;
};

/*
  Factory function. Argument types same as constructor.
  Returns a shared_ptr (can be seen in tests).
  A shared_ptr makes the most sense as a new object
  is created on the heap (on the stack would be impossible here).
  With heap allocation we must not forget to free it (i.e. delete).
  The simplest way of dealing with this is to use a
  shared_ptr, which takes care of deletion.
*/
std::shared_ptr<FlagParameter> flag(const std::string&);

#endif

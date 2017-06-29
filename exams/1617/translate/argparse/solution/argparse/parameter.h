#ifndef PARAMETER_H
#define PARAMETER_H

#include <string>
#include <list>


class Parameter
{
protected:
    /*
      m_name is a simple string, as each parameter has its own name
      Using shared pointer would enable us to have multiple parameters
      share the same name and change their names simultaneously. This
      kind of functionality makes no sense for parameters.
    */
	std::string m_name;

    /*
      Logic behind argument type:
        std::string        -> would be ok, but possibly inefficient since string would be copied due to pass-by-value
        std::string&       -> efficient, but gives write access to the constructor, which it does not need
        const std::string& -> efficient and readonly access
        std::string*       -> same as with std::string&, but clumsy syntax
        const std::string* -> same as with const std::string&, but clumsy syntax
        std::shared_ptr<std::string> -> same as std::string*, but useless overhead
    */
	Parameter(const std::string&);

public:
    /*
      virtual is needed to make it overridable
      = 0 is needed because it has no body (= abstract in java)
      virtual with dummy body would work, but it is less 'intentional': it would make it possible to create Parameter objects, which makes no sense
      Compare it to writing a dummy { return false; } body in java; making it abstract expresses your intent better, namely that there is no implementation at this level of abstraction

      Argument type: look at the tests!
      std::list was chosen because it actually simplifies the implementation: std::vector has no pop_front(), while std::list does.
      It should be a reference, because the parse-function needs to modify the list.
      If parse did not need to modify the list, it would be const std::list<std::string>&.
      Using std::list<std::string> (i.e. no reference) makes no sense: it would be inefficient, and the function's changes would be made to a copy of the list,
      not to the list itself.
    */
	virtual bool parse(std::list<std::string>&) = 0;
};

#endif

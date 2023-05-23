#ifndef METHOD_UNIT_H
#define METHOD_UNIT_H
#include <unit.h>
#include <vector>

class MethodUnit: public Unit
{

public:
    MethodUnit(const std::string& name,const std::string&  returnType,Flags flags )//constructor
        :m_name(name),m_returnType(returnType),m_flags(flags){}

    virtual void add(const std::shared_ptr<Unit>& unit,Flags = 0 ){}// add realisation of method


    virtual std::string compile(unsigned int level = 0) const{} // compile method into string

protected:
    std::string m_name; // name of function
    std::string m_returnType;// type of return value
    Flags m_flags;//Modificator of method as unsigned int
    std::vector<std::shared_ptr<Unit>> m_body;// vector of shared_ptr on Unit wich will contain realization of method
};

#endif // METHOD_UNIT_H

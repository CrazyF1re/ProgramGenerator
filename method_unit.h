#ifndef METHOD_UNIT_H
#define METHOD_UNIT_H
#include <unit.h>
#include <vector>

class MethodUnit: public Unit
{
public:
    enum Modifier {// enum with modificators of method
        STATIC  = 1,
        CONST   = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL   = 1 <<3,
        ABSTRACT = 1<<4
    };
public:
    MethodUnit(const std::string& name,const std::string&  returnType,Flags flags )//constructor
        :m_name(name),m_returnType(returnType),m_flags(flags){}


protected:
    std::string m_name; // name of function
    std::string m_returnType;// type of return value
    Flags m_flags;//Modificator of method as unsigned int
    std::vector<std::shared_ptr<Unit>> m_body;// vector of shared_ptr on Unit wich will contain realization of method
};

#endif // METHOD_UNIT_H

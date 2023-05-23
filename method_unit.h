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
        VIRTUAL = 1 << 2
    };
public:
    MethodUnit(const std::string& name,const std::string&  returnType,Flags flags )//constructor
        :m_name(name),m_returnType(returnType),m_flags(flags){}

    void add(const std::shared_ptr<Unit>& unit,Flags = 0 )// add realisation of method
    {
        m_body.push_back(unit);
    }

    std::string compile(unsigned int level = 0) const // compile method into string
    {
        std::string result = generateShift(level);// add shift
        if(m_flags & STATIC){ // here is just conjunction of m_flags and modificator
            result+="static ";}
        else if(m_flags & VIRTUAL){//one more conjunction
            result+="virtual ";
        }
        result += m_returnType+" ";
        result += m_name + "()";//if method is virtual it has no realization
        if(m_flags & CONST)//last conjunction
        {
            result+=" const";
        }
        result+=" {\n";
        for( const auto& b:m_body)
        {
            result+=b->compile(level+1);
        }
        result+=generateShift(level)+"}\n";
        return result;
    }

private:
    std::string m_name; // name of function
    std::string m_returnType;// type of return value
    Flags m_flags;//Modificator of method as unsigned int
    std::vector<std::shared_ptr<Unit>> m_body;// vector of shared_ptr on Unit wich will contain realization of method
};

#endif // METHOD_UNIT_H

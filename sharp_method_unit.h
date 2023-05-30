#ifndef SHARP_METHOD_UNIT_H
#define SHARP_METHOD_UNIT_H
#include "method_unit.h"

class sharp_method_unit:public MethodUnit
{


public:
    sharp_method_unit(const std::string & name, const std::string& returnType,Flags flags):MethodUnit(name,returnType,flags){}


    void add(const std::shared_ptr<Unit>& unit,Flags = 0 )// add realisation of method
    {
        m_body.push_back(unit);
    }
    std::string compile(unsigned int level = 0) const // compile method into string
    {
        std::string result = generateShift(level);// add shift
        if (m_flags & MethodUnit::STATIC)
        {
            result+="static ";
        }
        else if (m_flags & MethodUnit::VIRTUAL)
        {
            result+="virtual ";
        }
        result += m_returnType+" ";
        result += m_name + "()";//if method is virtual it has no realization

        result+=" {\n";
        for( const auto& b:m_body)
        {
            result+=b->compile(level+1);
        }
        result+=generateShift(level)+"}\n";
        return result;
    }
};

#endif // SHARP_METHOD_UNIT_H

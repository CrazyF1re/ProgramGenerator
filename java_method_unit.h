#ifndef JAVA_METHOD_UNIT_H
#define JAVA_METHOD_UNIT_H
#include "method_unit.h"

class java_method_unit:public MethodUnit
{
public:
    enum Modifier {// enum with modificators of method
        STATIC   = 1,
        FINAL    = 1<<1,
        ABSTRACT = 1<<2
    };
public:
    java_method_unit(const std::string & name, const std::string& returnType,Flags flags):MethodUnit(name,returnType,flags){}


    void add(const std::shared_ptr<Unit>& unit,Flags = 0 )// add realisation of method
    {
        m_body.push_back(unit);
    }
    std::string compile(unsigned int level = 0) const // compile method into string
    {
        std::string result = generateShift(level);// add shift
        if (m_flags & STATIC)
        {
            result+="static ";
        }
        else if (m_flags & FINAL)
        {
            result+="final ";
        }
        else if (m_flags & ABSTRACT)
        {
            result+="abstract ";
        }
        result += m_returnType+" ";
        result += m_name + "()";

        result+=" {\n";
        for( const auto& b:m_body)
        {
            result+=b->compile(level+1);
        }
        result+=generateShift(level)+"}\n";
        return result;
    }
};

#endif // JAVA_METHOD_UNIT_H

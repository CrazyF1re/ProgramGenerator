#ifndef CPP_METHOD_UNIT_H
#define CPP_METHOD_UNIT_H
#include "method_unit.h"

class cpp_method_unit : public MethodUnit
{

public:
    cpp_method_unit(const std::string & name, const std::string& returnType,Flags flags)//constructor which call default
        :MethodUnit(name,returnType,flags){}                                            //constructor from MethodUnit


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
        for( const auto& b:m_body)// cycle for each string into body of function add compile it into string and add to result
        {
            result+=b->compile(level+1);
        }
        result+=generateShift(level)+"}\n";//generate shift and close bracket
        return result;//return string in which we have finished function with realization and shifts
    }

};

#endif // CPP_METHOD_UNIT_H

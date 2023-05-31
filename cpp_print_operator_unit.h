#ifndef CPP_PRINT_OPERATOR_UNIT_H
#define CPP_PRINT_OPERATOR_UNIT_H
#include "print_operator_unit.h"

class cpp_print_operator_unit:public PrintOperatorUnit
{
public:
    cpp_print_operator_unit(const std::string& text):PrintOperatorUnit(text){}


    std::string compile(unsigned int level = 0)const// function to compile definition of function
    {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }
};

#endif // CPP_PRINT_OPERATOR_UNIT_H

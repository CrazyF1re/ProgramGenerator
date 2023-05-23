#ifndef PRINT_OPERATOR_UNIT_H
#define PRINT_OPERATOR_UNIT_H
#include <iostream>
#include "unit.h"

class PrintOperatorUnit:public Unit
{
public:
    explicit PrintOperatorUnit (const std::string& text): m_text(text){}// constructor

    std::string compile(unsigned int level = 0)const// function to compile definition of function
    {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }

private:
 std::string m_text; // string wich will  print

};

#endif // PRINT_OPERATOR_UNIT_H

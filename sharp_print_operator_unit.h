#ifndef SHARP_PRINT_OPERATOR_UNIT_H
#define SHARP_PRINT_OPERATOR_UNIT_H

#include "print_operator_unit.h"

class sharp_print_operator_unit:public PrintOperatorUnit
{
public:
    sharp_print_operator_unit(const std::string& text):PrintOperatorUnit(text){}

    std::string compile(unsigned int level = 0) const
    {
        return  generateShift(level) +"System.Console.WriteLine(\"" +m_text +"\");\n";
    }
};

#endif // SHARP_PRINT_OPERATOR_UNIT_H



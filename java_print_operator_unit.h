#ifndef JAVA_PRINT_OPERATOR_UNIT_H
#define JAVA_PRINT_OPERATOR_UNIT_H
#include "print_operator_unit.h"

class java_print_operator_unit: public PrintOperatorUnit
{
public:
    java_print_operator_unit(const std::string& text):PrintOperatorUnit(text){}

    std::string compile(unsigned int level = 0) const
    {
        return generateShift(level) + "System.out.println(\"" + m_text + "\");\n";
    }
};

#endif // JAVA_PRINT_OPERATOR_UNIT_H

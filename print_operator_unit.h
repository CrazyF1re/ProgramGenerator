#ifndef PRINT_OPERATOR_UNIT_H
#define PRINT_OPERATOR_UNIT_H
#include <iostream>
#include "unit.h"

class PrintOperatorUnit:public Unit
{
public:
    PrintOperatorUnit (const std::string& text): m_text(text){}// constructor

protected:
 std::string m_text; // string wich will  print

};

#endif // PRINT_OPERATOR_UNIT_H

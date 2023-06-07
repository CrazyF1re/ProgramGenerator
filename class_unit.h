#ifndef CLASS_UNIT_H
#define CLASS_UNIT_H
#include "unit.h"
#include <iostream>
#include <vector>

class ClassUnit : public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,// all
        PROTECTED,// all
        PRIVATE,// all
        INTERNAL,// C#
        PROTECTED_INTERNAL,// C#
        PRIVATE_PROTECTED//C#


    };

public:
    //here is just constructor with const name of Class and m_name = name
    ClassUnit(const std::string& name): m_name(name){}

protected:
    std::string m_name; // Name of class
    using Fields = std::vector<std::shared_ptr<Unit>>; // vector of shared ptr in which we will add some funcions (inherited from Unit)
    std::vector< Fields > m_fields; // vector of Fields (for each fiels like public protected etc.)

};


#endif // CLASS_UNIT_H

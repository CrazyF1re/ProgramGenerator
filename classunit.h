#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "unit.h"
#include <iostream>
#include <vector>

class ClassUnit : public Unit
{
public:
    enum AccessModifier{
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    const std::vector <std::string> ACCESS_MODIFIERS =
    {
      "public",
      "protected",
      "private"
    };

public:
    explicit ClassUnit(const std::string& name): m_name(name)
    {
        m_fields.resize( ACCESS_MODIFIERS.size());
    }

    void add (const std::shared_ptr<Unit>& unit, Flags flags);// add some func into class with

    std::string compile(unsigned int level = 0) const;

private:
    std::string m_name; // Name of class
    using Fields = std::vector<std::shared_ptr<Unit>>; // vector of shared ptr in which we will add some funcions (inherited from Unit)
    std::vector< Fields > m_fields; // vector of Fields

};


#endif // CLASSUNIT_H

#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "unit.h"
#include <iostream>
#include <vector>

class ClassUnit_Cpp : public Unit
{
public:
    enum AccessModifier{
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    const std::vector <std::string> ACCESS_MODIFIERS ={ "public","protected", "private" };

public:
    explicit ClassUnit_Cpp(const std::string& name): m_name(name)
    {
        m_fields.resize( ACCESS_MODIFIERS.size());
    }

    void add (const std::shared_ptr<Unit>& unit, Flags flags);

    std::string compile(unsigned int level = 0) const;

private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector< Fields > m_fields;

};
//const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public",
//"protected", "private" };

#endif // CLASSUNIT_H

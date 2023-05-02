#include "classunit.h"



void ClassUnit::add(const std::shared_ptr<Unit> &unit, Flags flags)
{
    int accessModifier = PRIVATE;
    if (flags<ACCESS_MODIFIERS.size())
    {
        accessModifier = flags;
    }

    m_fields[accessModifier].push_back(unit);
}

std::string ClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level)+ "class " + m_name + "{\n";
    for (size_t i = 0; i<ACCESS_MODIFIERS.size();i++)
    {
        if(m_fields[i].empty())
        {
            continue;
        }
        result+=ACCESS_MODIFIERS[i]+":\n";
        for(const auto& f:m_fields[i])
        {
            result+=f->compile(level+1);
        }
        result+="\n";
    }
    result+=generateShift(level) + "};\n";
    return result;
}

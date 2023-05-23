#ifndef CPP_CLASS_UNIT_H
#define CPP_CLASS_UNIT_H

#include "class_unit.h"

class cpp_class_unit :public ClassUnit
{
public:
    enum AccessModifier{//enum of methods of access
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    const std::vector <std::string> ACCESS_MODIFIERS = // vector of strings
    {
      "public",
      "protected",
      "private"
    };
public:

    cpp_class_unit(const std::string & name):ClassUnit(name)
    {
        m_fields.resize( ACCESS_MODIFIERS.size());
    }

    void add (const std::shared_ptr<Unit>& unit, Flags flags)
        {
            int accessModifier = PRIVATE; // set accessModifier private
            if (flags<ACCESS_MODIFIERS.size())// if flags less then size of vector ACCESS_MODIFIERS then set accessModifier
            {
                accessModifier = flags;
            }

            m_fields[accessModifier].push_back(unit);
        }
    std::string compile(unsigned int level = 0) const
    {
        std::string result = generateShift( level ) + "class " + m_name + " {\n"; // identify string wich will contain name of class and {
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )// cycle though each ACCESS_MODIFIER
        {
            if( m_fields[ i ].empty() )// if vector is empty just skip one iteration
            {
                continue;
            }
            result += ACCESS_MODIFIERS[ i ] + ":\n";// add access modificator into resul + shift on the one string
            for( const auto& f : m_fields[ i ] )// cycle into m_fields
            {
                result += f->compile( level + 1 );//call compile funtion for unit ptr stored into m_fields[i]
            }
            result += "\n";// add shift
        }

        result += generateShift( level ) + "};\n";//add closing bracket

        return result;
    }
};

#endif // CPP_CLASS_UNIT_H

#ifndef JAVA_CLASS_UNIT_H
#define JAVA_CLASS_UNIT_H

#include "class_unit.h"

class java_class_unit:public ClassUnit
{
public:
    // vector of strings
    const std::vector <std::string> ACCESS_MODIFIERS =
    {
      "public",
      "protected",
      "private"
    };

public:
    //constructor with name of class and modificator of access (default - public)
    java_class_unit(const std::string & name, Flags f = ClassUnit::PUBLIC):ClassUnit(name)
    {
        m_fields.resize( ACCESS_MODIFIERS.size());
        class_modificator = f;
    }

    //add function
    void add (const std::shared_ptr<Unit>& unit, Flags flags )
        {
            int accessModifier = ClassUnit::PRIVATE; // set accessModifier private
            if (flags<ACCESS_MODIFIERS.size())// if flags less then size of vector ACCESS_MODIFIERS then set accessModifier
            {
                accessModifier = flags;
            }

            m_fields[accessModifier].push_back(unit);
        }

    //compile into string
    std::string compile(unsigned int level = 0) const
    {
        std::string result = generateShift( level ) +ACCESS_MODIFIERS[class_modificator] + " "+ "class " + m_name + " {\n"; // identify string wich will contain name of class and {
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



private:
    Flags class_modificator;
};

#endif // JAVA_CLASS_UNIT_H

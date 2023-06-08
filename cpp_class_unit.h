#ifndef CPP_CLASS_UNIT_H
#define CPP_CLASS_UNIT_H

#include "class_unit.h"

class cpp_class_unit :public ClassUnit
{
public:

    cpp_class_unit(const std::string & name):ClassUnit(name) //constructor call default constructor from ClassUnit
    {
        m_fields.resize( PRIVATE + 1);//resize number of fields because for each language it has deffernt
                                                  //numbers of modifiers
    }

    void add (const std::shared_ptr<Unit>& unit, Flags flags) // add function with its modificator of access
        {
            Flags accessModifier = PRIVATE; // set accessModifier private
            if (flags<accessModifier)// if flags less then size of vector ACCESS_MODIFIERS then set accessModifier
            {
                accessModifier = flags;
            }

            m_fields[accessModifier].push_back(unit);//add to i-th vector of functions one more
        }
    std::string compile(unsigned int level = 0) const // output our class
    {
        std::string result = generateShift( level ) + "class " + m_name + " {\n"; // identify string wich will contain name of class and {
        for( size_t i = 0; i < m_fields.size(); ++i )// cycle though each ACCESS_MODIFIER
        {
            if( m_fields[ i ].empty() )// if vector is empty just skip one iteration
            {
                continue;
            }
            if (i == PUBLIC)// add access modificator into resul + shift on the one string
            {
                result+= "public:\n";
            }
            else if (i == PROTECTED)
            {
                result+= "protected:\n";
            }
            else if (i == PRIVATE)
            {
                result+= "private:\n";
            }
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

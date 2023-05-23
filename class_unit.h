#ifndef CLASS_UNIT_H
#define CLASS_UNIT_H
#include "unit.h"
#include <iostream>
#include <vector>

class ClassUnit : public Unit
{


public:
    explicit ClassUnit(const std::string& name): m_name(name)
    {

    }

    virtual void add (const std::shared_ptr<Unit>& unit, Flags flags){}// add some func into class with


    virtual std::string compile(unsigned int level = 0) const{}

    virtual ~ClassUnit(){}
protected:
    std::string m_name; // Name of class
    using Fields = std::vector<std::shared_ptr<Unit>>; // vector of shared ptr in which we will add some funcions (inherited from Unit)
    std::vector< Fields > m_fields; // vector of Fields

};


#endif // CLASS_UNIT_H

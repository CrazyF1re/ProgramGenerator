#ifndef FACTORY_H
#define FACTORY_H

#include "class_unit.h"
#include "method_unit.h"
#include "print_operator_unit.h"


#include <iostream>
class factory
{
public:
    virtual std::shared_ptr<ClassUnit> Create_Class(const std::string name){}
    virtual std::shared_ptr<MethodUnit> Create_Method(const std::string &func_name,
                                              const std::string &return_type,
                                                      const unsigned int &modificator){}
    virtual std::shared_ptr<PrintOperatorUnit> Create_Print(const std::string &body){}

    virtual ~factory(){}
};

#endif // FACTORY_H

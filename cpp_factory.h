#ifndef CPP_FACTORY_H
#define CPP_FACTORY_H
#include "factory.h"

#include "cpp_class_unit.h"
#include "cpp_method_unit.h"
#include "cpp_print_operator_unit.h"
class cpp_factory:public factory
{
public:
    std::shared_ptr<ClassUnit> Create_Class(const std::string name)
    {
        return std::make_shared<cpp_class_unit>(name);
    }
    std::shared_ptr<MethodUnit> Create_Method(const std::string &func_name,
                                              const std::string &return_type,
                                              const unsigned int &modificator)
    {
        return std::make_shared<cpp_method_unit>(func_name,return_type,modificator);
    }
    std::shared_ptr<PrintOperatorUnit> Create_Print(const std::string &body)
    {
        return std::make_shared<cpp_print_operator_unit>(body);
    }

};

#endif // CPP_FACTORY_H

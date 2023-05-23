#include <iostream>
#include "sharp_class_unit.h"
#include "method_unit.h"
#include "print_operato_runit.h"



std::string generateProgram()
{

      sharp_class_unit myClass("myClass",sharp_class_unit::INTERNAL);
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),
        sharp_class_unit::PUBLIC
    );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),
        sharp_class_unit::PRIVATE
    );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL |
        MethodUnit::CONST ),
        sharp_class_unit::INTERNAL
    );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc4", "void", MethodUnit::VIRTUAL |
        MethodUnit::CONST ),
        sharp_class_unit::INTERNAL_PROTECTED
    );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc5", "void", MethodUnit::STATIC ),
        sharp_class_unit::PROTECTED
    );
    auto method = std::make_shared< MethodUnit >( "testFunc6", "void",
    MethodUnit::STATIC );

    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, sharp_class_unit::PRIVATE_PROTECTED );
    return myClass.compile();
}


int main()
{
    std::cout<<generateProgram()<<std::endl;

    return 0;
}

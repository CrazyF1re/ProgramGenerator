#include <iostream>
#include "sharp_class_unit.h"
#include "sharp_method_unit.h"
#include "sharp_print_operator_unit.h"



std::string generateProgram()
{

      sharp_class_unit myClass("myClass");
    myClass.add(
        std::make_shared< sharp_method_unit>( "testFunc1", "void", 0 ),
        sharp_class_unit::PUBLIC
    );
    myClass.add(
        std::make_shared< sharp_method_unit >( "testFunc2", "void", sharp_method_unit::STATIC ),
        sharp_class_unit::PRIVATE
    );
    myClass.add(
        std::make_shared< sharp_method_unit >( "testFunc3", "void", sharp_method_unit::VIRTUAL),
        sharp_class_unit::PRIVATE
    );
    myClass.add(
        std::make_shared< sharp_method_unit >( "testFunc4", "void", sharp_method_unit::STATIC ),
        sharp_class_unit::PROTECTED
    );
    myClass.add(
        std::make_shared< sharp_method_unit >( "testFunc5", "void", sharp_method_unit::STATIC ),
        sharp_class_unit::PROTECTED
    );
    auto method = std::make_shared< sharp_method_unit >( "testFunc6", "void",
    sharp_method_unit::VIRTUAL );

    method->add( std::make_shared< sharp_print_operator_unit >( R"(Hello, world!\n)" ) );
    myClass.add( method, sharp_class_unit::PUBLIC );
    return myClass.compile();
}


int main()
{
    std::cout<<generateProgram()<<std::endl;

    return 0;
}

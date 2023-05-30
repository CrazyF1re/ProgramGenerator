#include <iostream>
#include "java_class_unit.h"
#include "java_method_unit.h"
#include "java_print_operator_unit.h"

#include "cpp_factory.h"
#include "factory.h"

//std::string generateProgram()
//{

//      java_class_unit myClass("myClass");
//    myClass.add(
//        std::make_shared< java_method_unit>( "testFunc1", "void", 0 ),
//        java_class_unit::PUBLIC
//    );
//    myClass.add(
//        std::make_shared< java_method_unit >( "testFunc2", "void", java_method_unit::STATIC ),
//        java_class_unit::PRIVATE
//    );
//    myClass.add(
//        std::make_shared< java_method_unit >( "testFunc3", "void", java_method_unit::ABSTRACT),
//        java_class_unit::PRIVATE
//    );
//    myClass.add(
//        std::make_shared< java_method_unit >( "testFunc4", "void", java_method_unit::STATIC ),
//        java_class_unit::PROTECTED
//    );
//    myClass.add(
//        std::make_shared< java_method_unit >( "testFunc5", "void", java_method_unit::STATIC ),
//        java_class_unit::PROTECTED
//    );
//    auto method = std::make_shared< java_method_unit >( "testFunc6", "void",0);

//    method->add( std::make_shared< java_print_operator_unit >( R"(Hello, world!\n)" ) );
//    myClass.add( method, java_class_unit::PUBLIC );
//    return myClass.compile();
//}
std::string generateProgram2(std::shared_ptr<factory> fac)
{

    auto myClass =fac->Create_Class("Test");
    return myClass->compile();
}

int main()
{
    auto Myclass = std::shared_ptr<cpp_factory>();
    std::cout<<generateProgram2(Myclass)<<std::endl;

    return 0;
}

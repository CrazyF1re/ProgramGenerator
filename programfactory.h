#ifndef PROGRAMFACTORY_H
#define PROGRAMFACTORY_H

#include "factory.h"

#include <iostream>

class ProgramFactory
{
public:
    ProgramFactory(std::unique_ptr<factory> fac)
    {
        f = std::move(fac);
    }

    std::string GenerateProgram_1()
    {
        std::cout<<"FIRST TEST\n\n";
        auto myClass = f->Create_Class("myClass");
        myClass->add(f->Create_Method("testFunc1", "void", 0),ClassUnit::PUBLIC);
        myClass->add(f->Create_Method("testFunc2", "void", MethodUnit::STATIC),ClassUnit::PRIVATE);
        myClass->add(f->Create_Method("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::ABSTRACT),ClassUnit::PUBLIC);

        auto  method = f->Create_Method("testFunc4","void",MethodUnit::STATIC);
        auto print = f->Create_Print("Here is Func 4");
        method->add(print);
        myClass->add(method,ClassUnit::PROTECTED);
        return myClass->compile();
    }
    std::string GenerateProgram_2()
    {
        std::cout<<"\nSECOND TEST\n\n";
        auto Person = f->Create_Class("Person");
        auto Account = f->Create_Class("Account");
        Person->add(Account,ClassUnit::PRIVATE);
        Person->add(f->Create_Method("Person","",0),ClassUnit::PUBLIC);
        Person->add(f->Create_Method("print","void",0),ClassUnit::PUBLIC);
        Account->add(f->Create_Method("Account","",0),ClassUnit::PUBLIC);

        return Person->compile();
    }
private:
    std::unique_ptr<factory> f;
};

#endif // PROGRAMFACTORY_H

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

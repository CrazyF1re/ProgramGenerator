#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"

std::string generateProgram()
{
    ClassUnit_Cpp myClass("myClass");
    myClass.add(
        std::make_shared< MethodUnit_Cpp >( "testFunc1", "void", 0 ),
        ClassUnit_Cpp::PUBLIC
    );
    myClass.add(
        std::make_shared< MethodUnit_Cpp >( "testFunc2", "void", MethodUnit_Cpp::STATIC ),
        ClassUnit_Cpp::PRIVATE
    );
    myClass.add(
        std::make_shared< MethodUnit_Cpp >( "testFunc3", "void", MethodUnit_Cpp::VIRTUAL |
        MethodUnit_Cpp::CONST ),
        ClassUnit_Cpp::PUBLIC
    );
    auto method = std::make_shared< MethodUnit_Cpp >( "testFunc4", "void",
    MethodUnit_Cpp::STATIC );

    method->add( std::make_shared< PrintOperatorUnit_Cpp >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit_Cpp::PROTECTED );
    return myClass.compile();
}


int main(int argc, char *argv[])
{
    std::cout<<generateProgram()<<std::endl;
    return 0;
}

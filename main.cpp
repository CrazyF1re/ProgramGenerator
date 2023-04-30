#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"

std::string generateProgram()
{
    ClassUnit myClass("myClass");
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
    );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),
        ClassUnit::PRIVATE
    );
    myClass.add(
        std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL |
        MethodUnit::CONST ),
        ClassUnit::PUBLIC
    );
    auto method = std::make_shared< MethodUnit >( "testFunc4", "void",
    MethodUnit::STATIC );

    method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );
    return myClass.compile();
}


int main(int argc, char *argv[])
{
    std::cout<<generateProgram()<<std::endl;
    return 0;
}

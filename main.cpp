#include <iostream>


#include "cpp_factory.h"
#include "java_factory.h"
#include "sharp_factory.h"
#include "programfactory.h"





int main()
{
    ProgramFactory* p = new ProgramFactory(std::make_unique<cpp_factory>());
    std::cout<<p->GenerateProgram_1();
    std::cout<<p->GenerateProgram_2();
    delete p;
    return 0;
}

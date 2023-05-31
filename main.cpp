#include <iostream>


#include "cpp_factory.h"
#include "java_factory.h"
#include "sharp_factory.h"
#include "programfactory.h"





int main()
{
    ProgramFactory* p = new ProgramFactory(new sharp_factory);
    std::cout<<p->GenerateProgram();
    delete p;
    return 0;
}

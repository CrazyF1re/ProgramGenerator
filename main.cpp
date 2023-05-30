#include <iostream>


#include "cpp_factory.h"
#include "java_factory.h"
#include "sharp_factory.h"
#include "programfactory.h"

class test1
{
public:
  virtual void func1();
  virtual ~test1(){}
};
class test2:public test1
{
public:
    void func1(){}
    ~test2(){}

};



int main()
{
    //auto Myclass = std::shared_ptr<cpp_factory>();
    //std::cout<<generateProgram2(Myclass)<<std::endl;

    ProgramFactory* p = new ProgramFactory(new cpp_factory);
    std::cout<<p->GenerateProgram();
    delete p;
    return 0;
}

#ifndef UNIT_H
#define UNIT_H
#include <iostream>
#include <memory>


class Unit
{
public:
    using Flags = unsigned int; // definition Flags as unsigned int
public:
    virtual ~Unit() = default; // virtual destructor couse we wiil inherit from this class

    virtual void add( const std::shared_ptr< Unit >&,Flags = 0){}

    virtual std::string compile(Flags level =0)const = 0;

protected:
    virtual std::string generateShift( Flags level)const
    {
        static const auto  DEFAULT_SHIFT = "    ";
        std::string result;
        for( unsigned int i =0; i <level;++i)
        {
            result+=DEFAULT_SHIFT;
        }
        return result;
    }
};

#endif // UNIT_H

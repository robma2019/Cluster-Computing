#include <iostream>
#include "Func.h"

void Func::first()
{
    for(int i = 0; i < 5; i++)
        std::cout << "Func: first_" << i << std::endl;
}

void Func::second()
{
    for(int i = 0; i < 100; i++)
    {
        std::cout << "Func: second_" << i << std::endl;
    }
}

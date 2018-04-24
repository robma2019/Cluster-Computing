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

void Func::third(int n)
{
    std::cout << "Number recieved " << n << std::endl;
    if(n == 0)
    {
        std::cout << "ERROR: Number not read.\n";
        return;
    }
    for(int i = 0; i <= n; i++)
    {
        int sum = 0;
        for(int  j = 1; j < i; j++ )
        {
            if(i % j == 0)
            {
                sum += j;
            }
        }

        if(sum == i)
        {
            std::cout << i << std::endl;
        }

    }
}

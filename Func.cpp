#include <iostream>
#include "Func.h"

//static void Func::first()
void Func::first()
{
    for(int i = 0; i < 5; i++)
        std::cout << "Func: first_" << i << std::endl;
}

//static void Func::second()
void Func::second()
{
    for(int i = 0; i < 100; i++)
    {
        std::cout << "Func: second_" << i << std::endl;
    }
}

//static void Func::third()
void Func::third()
{
    //std::cout << "Number recieved " << n << std::endl;
    //if(n == 0)
    //{
    //    std::cout << "ERROR: Number not read.\n";
    //    return;
    //}
    for(int i = 0; i <= 10000; i++)
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
            std::cout << "Perfect number: " << i << std::endl;
        }

    }
}

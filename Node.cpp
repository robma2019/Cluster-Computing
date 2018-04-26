#include <iostream>
#include "Node.h"
#include <thread>

//typedef void (*funcIn)(int);

int Node::getCap()
{
    return memory;
}

bool Node::isFree()
{
    return free;
}

void Node::setThread( void(*func)() )
{
    thisThread = std::thread(func);
    free = false;
}

void Node::setThread( void(*f)(int), int i)
{
    std::cout << "Num: " << i << std::endl;
    thisThread = std::thread(f, i);
    //std::cout << "call function directly: "; 
    //f(i);
    free = false;
}

//std::thread Node::pass(void (*f)(int), int j)
//{
//    return std::thread(f, j);
//}

void Node::start()
{
    thisThread.join();
    free = true;
}

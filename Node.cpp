#include <iostream>
#include "Node.h"

typedef void (*funcIn)(int);

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

void Node::setThread(funcIn f, int j)
{
    thisThread = std::thread(f, j);
}

void Node::start()
{
    thisThread.join();
    free = true;
}

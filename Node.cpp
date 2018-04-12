#include <iostream>
#include "Node.h"

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

void Node::start()
{
    thisThread.join();
    free = true;
}

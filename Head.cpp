#include <iostream>
#include <thread>
#include "Head.h"
#include "Node.h"
#include "Func.h"

void Head::addNode(int capacity)
{
    children.push_back(Node(capacity));
}

std::string Head::getName()
{
    return hName;
}

void Head::setThread(void (*f)() )
{
    thisThread = std::thread(f);
}

void Head::do_job()
{
    thisThread.join();
}

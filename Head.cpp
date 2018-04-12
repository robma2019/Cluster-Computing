#include <iostream>
#include <thread>
#include "Head.h"
#include "Node.h"
#include "Func.h"

void Head::addNode(int capacity)
{
    children.push_back(Node(capacity));
}

bool Head::isFree()
{
    return free;
}

std::string Head::getName()
{
    return hName;
}

int Head::nodeCount()
{
    return children.size();
}

int Head::jobCount()
{
    return queue.size();
}

void Head::removeN(int index)
{
    if(index < children.size())
        children.erase(children.begin()+index,children.begin()+index+1);
}

void Head::removeJ(int index)
{
    if(index < queue.size())
        queue.erase(queue.begin()+index,queue.begin()+index+1);
}

//std::string Head::getNode(int index)
//{
//    return "node" << index << ": " << children[index].getCap();
//}

void Head::enqueue(type t, bool priority)
{
    if(priority)
        queue.insert(queue.begin(),t);
    else
        queue.push_back(t);
}

bool Head::setNext()
{
    if(queue.size() == 0){
        std::cout << "Queue is empty, add a new Job!\n";
        return false;
    }
    thisThread = std::thread(queue[0]);  
    queue.erase(queue.begin(),queue.begin()+1);
    return true;
}

bool Head::assign()
{
    if(queue.size() < 1)
    {
        std::cout << "ERROR: Empty queue, try to add a task then try again.\n";
        return false;
    }

    if(children.size() < 1)
    {
        std::cout << "ERROR: No compute nodes, try adding a compute node and try again.\n";
        return false;
    }

    while(queue.size() > 0)
    {
        int numFull = 0;
        for(int i = 0; i < children.size(); i++)
        {
            if(children[i].isFree())
            {
                children[i].setThread(queue[0]);
                queue.erase(queue.begin(),queue.begin()+1);
                numFull = 0;
            }
            else
                numFull++;
        }
        if(numFull == children.size()-1)
            break;;
    }

    std::cout << "Queue is empty or all Nodes have a job, ready to run!\n";
    return true;
}

void Head::start()
{
    for(int i = 0; i < children.size(); i++)
    {
        if(!children[i].isFree())
        {
            children[i].start();
        }
    }

    std::cout << "All done!\n";
}

void Head::setThread()
{
    //thisThread = std::thread();
}

void Head::do_job()
{
    thisThread.join();
}

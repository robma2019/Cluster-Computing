#include <iostream>
#include <thread>

#ifndef NODE_H
#define NODE_H

class Node
{
    private:
        int memory;
        std::thread thisThread;
        int lData;
        int hData;

    public:
        Node(int capacity)
        {
            memory = capacity;
        }
        void doWhat();
};

#endif

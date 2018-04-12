#include <iostream>
#include <vector>
#include <thread>
#include "Func.h"
#include "Node.h"

#ifndef HEAD_H
#define HEAD_H

typedef void (*type)(void);

class Head
{
    private:
        bool free;
        std::string hName;
        std::thread thisThread;
        std::vector<Node> children;
        std::vector<type> queue;

    public:
        Head(std::string name)
        {
            hName = name;
            free = true;
        }
        std::string getName();
        std::string getNode(int);
        int nodeCount();
        int jobCount();
        void removeN(int);
        void removeJ(int);
        bool isFree();
        bool assign();
        void start();
        void enqueue(type,bool);
        bool setNext();
        void setThread();
        void addNode(int capacity);
        void do_job();
        //void send_job(Node, functiontype, int, int);  
};

#endif

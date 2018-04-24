#include <iostream>
#include <vector>
#include <thread>
#include "Func.h"
#include "Node.h"

#ifndef HEAD_H
#define HEAD_H

typedef void (*type)(void);
typedef void (*typeInput)(int);

struct Intype
{
    typeInput t;
    int in;
};

class Head
{
    private:
        bool free;
        std::string hName;
        std::thread thisThread;
        std::vector<Node> children;
        std::vector<type> queue;
        std::vector<Intype> queueIn;

    public:
        Head(std::string name)
        {
            hName = name;
            free = true;
        }
        std::string getName();
        int getNode(int);
        int nodeCount();
        int jobCount();
        void removeN(int);
        void removeJ(int);
        bool isFree();
        bool assign();
        void start();
        void enqueue(type,bool);
        void enqueue(typeInput, int);
        bool setNext();
        void setThread();
        void addNode(int capacity);
        void do_job();
        //void send_job(Node, functiontype, int, int);  
};

#endif

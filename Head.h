#include <iostream>
#include <vector>
#include <thread>
#include "Func.h"
#include "Node.h"

#ifndef HEAD_H
#define HEAD_H

//typedef void (Func::*functiontype)(void);

class Head
{
    private:
        //functiontype fun;
        std::string hName;
        std::thread thisThread;
        int lData; //Lower limit for dataset
        int hData; //Upper limit for dataset
        std::vector<Node> children;

    public:
        Head(std::string name)
        {
            hName = name;
        }
        std::string getName();
        void setThread(void (*f)() );
        void addNode(int capacity);
        void do_job();
        //void send_job(Node, functiontype, int, int);  
};

#endif

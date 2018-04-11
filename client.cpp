#include <iostream>
#include <vector>
#include "Head.h"
#include "Node.h"
#include "Func.h"

using namespace std;
string commands[6];
vector<Head> cluster;
bool filled = false;
bool running = true;

void fill_command(string *comms);
int index(string findName);
string parse_command(string command);
void makeHead(std::string name);
void listHead();

int main(void)
{
    //cluster = vector<Head>(1);
    
    cout << "initializing...\n";
    fill_command(commands);
    for(int i = 0; i < 5; i++)
    {
        cout << commands[i] << endl;
    }
    string com;
    string wExtra;
    int iExtra;
    while(running)
    {
        cout << "Try entering a comand\n";
        cin >> com;
        if(parse_command(com) == "success")
        {
            //Do the command
            if(com == "quit")
            {
                running = false;
                
            }
            if(com == "addHead")
            {
                //make master node
                cout << "Provide a name for your Head node\n";
                cin >> wExtra;
                makeHead(wExtra);
            }
            if(com == "addNode")
            {
               //make compute node
                cout << "Give a name of a master node to add a compute node to.\n";
                cout << "Or enter (default) to add it to the first head node in the list.\n";
                cin >> wExtra;
                if(wExtra == "default")
                {
                    cout << "How much processing power should this node have? (E.g. (1024)Kb)\n";
                    cin >> iExtra;
                    cluster[0].addNode(iExtra);
                }
                else
                {
                    if(index(wExtra) != -1)
                    {
                        cout << "How much processing power should this node have? (E.g. (1024)Kb)\n";
                        cin >> iExtra;
                        cluster[index(wExtra)].addNode(iExtra);
                    }
                    else
                        cout <<  "No Head node of name(" << wExtra << ") found.\n";
                } 
            }
            if(com == "listHead")
            {
                cout << "should list here!!!\n";
                listHead();
            }
            if(com == "index")
            {
                cout << "Enter a name to find its index: ";
                cin >> wExtra;
                cout << "Index: " << index(wExtra) << endl;
            }
            if(com == "test")
            {
                cluster[0].setThread(Func::first);
                cluster[0].do_job();
            }
        } else {
            if(parse_command(com) == "")
                cout << "Empty Command\n";
            cout << parse_command(com) << endl;
        }

    }

    return 0;
}

void fill_command(string *comms)
{
    comms[0] = "quit";
    comms[1] = "addHead";
    comms[2] = "addNode";
    comms[3] = "listHead";
    comms[4] = "index";
    comms[5] = "test";
}

int index(string findName) //Retuns index of object whos name matches the requested parameter
{                          // -1 if it doesn't exist.
    for(int i = 0; i < cluster.size(); i++)
    {
        if(cluster[i].getName() == findName)
        {
            cout << cluster[i].getName() << "<---[" << i << "]" << endl;
            return i;
        }
   }

    return -1;
}

string parse_command(string command)
{
    if(command == "" || command == "\n")
        return "";
    for(int i = 0; i < 6; i++)
    {
        if(command == commands[i])
        {
            return "success";
        }
    }
    return "Unknown command: " + command;
}

void makeHead(string name)
{
    cluster.push_back(Head(name));
}

void listHead()
{
    for(int i = 0; i < cluster.size(); i++)
    {
        cout << cluster[i].getName() << endl;
    }
}

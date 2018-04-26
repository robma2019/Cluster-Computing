#include <iostream>
#include <vector>
#include "Head.h"
#include "Node.h"
#include "Func.h"

using namespace std;
string commands[8];
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
    for(int i = 0; i < 8; i++)
    {
        cout << commands[i] << endl;
    }
    string com;
    string wExtra;
    int iExtra;
    while(running)
    {
        cout << "Try entering a command\n";
        cin >> com;
        if(parse_command(com) == "success")
        {
            //Do the command
            if(com == "quit")
            {
                cout << "Are you sure you want to drop out of clarkson? (y/n)";
                cin >> wExtra;
                if(wExtra == "y")
                {
                    running = false;
                }
                else
                {
                    //Dont quit
                }
                
            }
            if(com == "addHead")
            {
                //make master node
                cout << "Provide a name for your Head node\n";
                cin >> wExtra;
                if(index(wExtra) == -1)
                {
                    makeHead(wExtra);
                }
                else
                {
                    cout << "WARNING: Head node with this name already exist's, please chose a different name.\n";
                }
            }
            if(com == "addNode")
            {
                //make compute node
                if(cluster.size() < 1)
                {
                    cout << "There are no Head nodes to add this too, Please create a Head node first!\n";
                }
                else if(cluster.size() == 1)
                {
                    cout << "How much processing power should this node have? (E.g. (1024)Kb)\n";
                    cin >> iExtra;
                    cluster[0].addNode(iExtra);
                }
                else
                {
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
            }
            if(com == "listHead")
            {
                //cout << "should list here!!!\n";
                listHead();
            }
            if(com == "index")
            {
                cout << "Enter a name to find its index: ";
                cin >> wExtra;
                cout << "Index: " << index(wExtra) << endl;
            }
            if(com == "add")
            {
                if(cluster.size() < 1)
                {
                    cout << "No head node exists, try making a head first.\n";
                }
                else if(cluster.size() == 1)
                {
                    cout << "Enter a number representing which function to add (0-2)\n";
                    cin >> iExtra;
                    switch(iExtra)
                    {
                        default:
                            cout << "Function request not recognized.\n";
                            break;

                        case 0:
                            cluster[0].enqueue(Func::first,false);
                            break;

                        case 1:
                            cluster[0].enqueue(Func::second,false);
                            break;

                        case 2:
                            cout << "To what degree would you like to test? ";
                            cin >> iExtra;
                            cout << "\n";
                            cluster[0].enqueue(Func::third,false);
                    }
                }
                else
                {
                    cout << "Which head? ";
                    cin >> wExtra;
                    if(index(wExtra) == -1)
                    {
                        cout << "Head name not recognized\n";
                    }
                    else
                    {
                        cout << "Enter a number representing which function to add (0-2)\n";
                        cin >> iExtra;
                        switch(iExtra)
                        {
                            default:
                                cout << "Function request not recognized.\n";
                                break;

                            case 0:
                                cluster[index(wExtra)].enqueue(Func::first,false);
                                break;

                            case 1:
                                cluster[index(wExtra)].enqueue(Func::second,false);
                                break;

                            case 2:
                                cout << "To what degree would you like to test? ";
                                cin >> iExtra;
                                cout << "\n";
                                cluster[index(wExtra)].enqueue(Func::third, false);
                        }
                    }
                }
            }
            if(com == "start")
            {
                if(cluster.size() == 1)
                {
                    if(cluster[0].assign())
                        cluster[0].start();
                }
                else
                {
                    cout << "Which head? ";
                    cin >> wExtra;
                    if(index(wExtra) != -1)
                    {
                        if(cluster[index(wExtra)].assign())
                            cluster[index(wExtra)].start();
                    }
                    else
                        cout << "Head name not recognized.\n";
                }
            }
            if(com == "delete")
            {
                cout << "What do you wish to delete? (head,node,job) ";
                cin >> wExtra;
                if(wExtra == "head")
                {
                    cout << "Which head? ";
                    cin >> wExtra;
                    cout << "\n";
                    if(index(wExtra) != -1)
                    {
                        string currentName = wExtra;
                        cout << "You are about to delete (" << wExtra << ") and all of its children, are you sure? (y/n)";
                        cin >> wExtra;
                        if(wExtra == "y")
                        {
                            cluster.erase(cluster.begin()+index(currentName),cluster.begin()+index(currentName)+1);
                            cout << currentName << " was successfully removed.\n";
                        }
                        else
                        {
                            cout << "Nothing was removed.\n";
                        }
                    }
                    else
                    {
                        cout << "Head name not recognized.\n";
                    }
                }
                else if(wExtra == "node")
                {
                    cout << "Which head is the parent of the Node you wish to remove.\n";
                    cin >> wExtra;
                    if(index(wExtra) != -1)
                    {
                        string currentName = wExtra;
                        cout << "You are about to remove a compute node from (" << wExtra << ") , are you sure? (y/n) ";
                        cin >> wExtra;
                        if(wExtra == "y")
                        {
                            if(cluster[index(currentName)].nodeCount() < 1)
                            {
                                cout << "ERROR: this head node actually contains no compute nodes.\n";
                            }
                            else
                            {
                                cout << "Enter an index of a node (0-" << cluster[index(currentName)].nodeCount()-1 << ") ";
                                cin >> iExtra;
                                cluster[index(currentName)].removeN(iExtra);
                            }
                        }
                        else
                        {
                            cout << "Nothing was removed\n";
                        }
                    }
                    else
                    {
                        cout << "Head name not recognized.\n";
                    }
                }
                else if(wExtra == "job")
                {
                    cout << "Which head is the parent of the job you wish to delete? ";
                    cin >> wExtra;
                    if(index(wExtra) != -1)
                    {
                        string currentName = wExtra;
                        cout << "You are about to remove a queue'd job from (" << currentName << ") , are you sure? (y/n) ";
                        cin >> wExtra;
                        if(wExtra == "y")
                        {
                            if(cluster[index(currentName)].jobCount() < 1)
                            {

                            }
                            else
                            {
                                cout << "Enter an index of a job (0-" << cluster[index(currentName)].jobCount()-1 << ") ";
                                cin >> iExtra;
                                cluster[index(currentName)].removeJ(iExtra);
                            }
                        }
                        else
                        {
                            cout << "Nothing was removed.\n";
                        }
                    }
                    else
                    {
                        cout << "Head name not recognized.\n";
                    }
                }
                else
                {
                    cout << "Decision not recognized.\n";
                }
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
    comms[5] = "add";
    comms[6] = "start";
    comms[7] = "delete";
}

int index(string findName) //Retuns index of object whos name matches the requested parameter
{                          // -1 if it doesn't exist.
    for(int i = 0; i < cluster.size(); i++)
    {
        if(cluster[i].getName() == findName)
        {
            //cout << cluster[i].getName() << "<---[" << i << "]" << endl;
            return i;
        }
   }

    return -1;
}

string parse_command(string command)
{
    if(command == "" || command == "\n")
        return "";
    for(int i = 0; i < 8; i++)
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
    cout << "################### Head Tree ###########################\n";
    for(int i = 0; i < cluster.size(); i++)
    {
        cout << cluster[i].getName() << endl;
        if(cluster[i].nodeCount() > 0)
        {
            for(int j = 0; j < cluster[i].nodeCount(); j++)
            {
                cout << "|-->" << "node" << j << ": " << cluster[i].getNode(j) << endl;
            }
        }
    }
}

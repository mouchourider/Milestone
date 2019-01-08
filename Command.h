#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <vector>
using namespace std;

class Command {
public:
    // pure virtual function
    virtual int execute(vector<string> cmdTemp, int index) = 0;
};

#endif

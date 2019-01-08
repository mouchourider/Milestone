#ifndef PARSER_H
#define PARSER_H
#include "Command.h"
#include <string.h>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Parser {
 public:
    Parser();          // public constructor
    ~Parser();
    Parser(const Parser&);  // public copy constructor
    void strPrs(vector<string> vecStr);
    int strPrsTarget(vector<string> vecStr, int start, string stop);

private:
    map<string, Command* > mapCmd;
};

#endif

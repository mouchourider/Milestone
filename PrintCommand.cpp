//
// Created by franckito on 12/18/18.
//

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "PrintCommand.h"
#include "Command.h"
#include "GlobalTables.h"
#include "ShuntingYard.h"

int PrintCommand::execute(vector<string> cmdTemp, int index){
    ShuntingYard* sY = new ShuntingYard();
    GlobalTables* gT = new GlobalTables();
    int endLine = enterKey(cmdTemp, index);
    string temp = vectorToString(cmdTemp, index + 1, index + endLine);
    if(gT->keyExists(temp))
        printMeth(to_string(symbolTable.at(temp)));
    else if(temp.find("\"")== string::npos)
        printMeth(to_string(sY->calculate(temp)));
    else
        printMeth(temp);
delete sY;
delete gT;
    return endLine;
}

void PrintCommand::printMeth(string message) {
    cout << message << endl;
}

string PrintCommand::vectorToString(vector<string> vector, int index, int end) {
    string ret = vector.at(index);
    int i = 1;
    while(index + i < end){
        ret += vector.at(index + i);
    }
    return ret;
}

int PrintCommand::enterKey(vector<string> vector, int index){
    int i = 0;
    while(vector.at(index + i) != "\n") {
        i++;
    }
    return i;
}

PrintCommand::~PrintCommand() = default;

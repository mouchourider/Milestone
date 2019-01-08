//
// Created by franckito on 12/18/18.
//

#ifndef UNTITLED1_PrintCommand_H
#define UNTITLED1_PrintCommand_H
#include "Command.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

class PrintCommand: public Command {
public:
    virtual int execute(vector<string> cmdTemp, int index) override;
    void printMeth(string message);
    string vectorToString(vector<string> vector, int index, int end);
    int enterKey(vector<string> vector, int index);
    ~PrintCommand();
};
#endif //UNTITLED1_PrintCommand_H

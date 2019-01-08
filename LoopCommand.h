//
// Created by franckito on 12/19/18.
//

#ifndef UNTITLED1_LoopCommand_H
#define UNTITLED1_LoopCommand_H
#include "Command.h"
#include "ConditionParser.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <map>
class LoopCommand: public ConditionParser {
    string type;
    int socketLay;
public:
    explicit LoopCommand(string type);
    int execute(vector<string> cmdTemp, int index) override;
    int enterKey(vector<string> vector, int index) override;
    ~LoopCommand();
};
#endif //UNTITLED1_LoopCommand_H

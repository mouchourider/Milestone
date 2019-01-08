//
// Created by newbuntu on 26/12/18.
//

#ifndef UNTITLED1_IfCommand_H
#define UNTITLED1_IfCommand_H
#include "Command.h"
#include "ConditionParser.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <map>
class IfCommand: public ConditionParser {
public:

    IfCommand();
    int execute(vector<string> cmdTemp, int index) override;
    int enterKey(vector<string> vector, int index) override;
    ~IfCommand();
};
#endif //UNTITLED1_IfCommand_H


//
// Created by franckito on 12/19/18.
//

#ifndef UNTITLED1_ChangeCommand_H
#define UNTITLED1_ChangeCommand_H
#include "Command.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <map>

class ChangeCommand: public Command {
public:

int execute(vector<string> cmdTemp, int index) override;

void changeData(string location, string nValue);

int enterKey(vector<string> cmdTemp, int index);

string vectorToString(vector<string> vector, int index, int end);
};

#endif //UNTITLED1_ChangeCommand_H

//
// Created by franckito on 12/18/18.
//

#ifndef UNTITLED1_VarCommand_H
#define UNTITLED1_VarCommand_H
#include "Command.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <map>
class VarCommand: public Command {
public:
    VarCommand();

    int execute(vector<string> cmdTemp, int index) override;

    void bind(string location, string var);

    void bindSet(string var, string value);

    void bindSetExpression(string var, vector<string> cmdTemp, int index, int end);

    int enterKey(vector<string> cmdTemp, int index);

    bool is_expression(vector<string> cmdTemp, int index, int end);

    string vectorToString(vector<string> vector, int i, int anEnd);

    void repExistingVal(vector<string> vector, string basic_string);

    ~VarCommand();
};
#endif //UNTITLED1_VarCommand_H

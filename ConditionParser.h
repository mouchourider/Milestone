//
// Created by franckito on 12/20/18.
//

#ifndef UNTITLED1_CONDITIONPARSER_H
#define UNTITLED1_CONDITIONPARSER_H
#include "Command.h"

class ConditionParser : public Command{
    string a;
    string op;
    string b;

public:
    int execute(vector<string> cmdTemp, int index) override;
    int conditionReader(vector<string> cmdLines, int index);
    bool check();
    string vectorToString(vector<string> vector, int index, int end);
    int opCheck(vector<string> vector, int index);
    virtual int enterKey(vector<string> vector, int index);
};

#endif //UNTITLED1_CONDITIONPARSER_H

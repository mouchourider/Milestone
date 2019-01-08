//
// Created by newbuntu on 26/12/18.
//

#ifndef UNTITLED1_SleepCommand_H
#define UNTITLED1_SleepCommand_H
#include "Command.h"
class SleepCommand: public Command {
public:
    int execute(vector<string> cmdTemp, int index) override;
    string vectorToString(vector<string> vector, int index, int end);
    int enterKey(vector<string> vector, int index);

};
#endif //UNTITLED1_SleepCommand_H

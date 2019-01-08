//
// Created by newbuntu on 27/12/18.
//

#ifndef UNTITLED1_EnterCommand_H
#define UNTITLED1_EnterCommand_H
#include "Command.h"
class EnterCommand: public Command {

public:
    int execute(vector<string> cmdTemp, int index) override;
};
#endif //UNTITLED1_EnterCommand_H

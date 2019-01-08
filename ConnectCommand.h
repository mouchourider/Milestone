//
// Created by franckito on 12/17/18.
//

#ifndef UNTITLED1_ConnectCommand_H
#define UNTITLED1_ConnectCommand_H
#include "Command.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

class ConnectCommand: public Command {

   public:
    ConnectCommand();
    int execute(vector<string> cmdTemp, int index) override;
    void connectSocket(int port, string ip);
    static void *updateVal(void *args);
    int enterKey(vector<string> cmdTemp, int index);
    string vectorToString(vector<string> vector, int index, int end);
    ~ConnectCommand();
};

#endif //UNTITLED1_ConnectCommand_H

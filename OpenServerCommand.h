//
// Created by franckito on 12/17/18.
//

#ifndef UNTITLED1_OpenServerCommand_H
#define UNTITLED1_OpenServerCommand_H
#include "Command.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>

class OpenServerCommand: public Command {
public:
    // pure virtual function
    int port, time;
    virtual int execute(vector<string> cmdTemp, int index);
    void openSocket(int port, int time);
    static void *runServer(void *args);
    static vector<double> buffToDouble(string buffer);
    static void *updateTable(vector<double> temp);
    int enterKey(vector<string> vec, int index);
    string vectorToString(vector<string> vector, int index, int end);
    ~OpenServerCommand();
};


#endif //UNTITLED1_OpenServerCommand_H

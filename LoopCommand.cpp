//
// Created by franckito on 12/19/18.
//
//
// Created by franckito on 12/18/18.
//
#include "Command.h"
#include "VarCommand.h"
#include "Parser.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include "ConnectCommand.h"
#include <sys/socket.h>
#include "LoopCommand.h"


int LoopCommand::execute(vector<string> cmdTemp, int index){
    Parser* p = new Parser();
    int endLine = enterKey(cmdTemp, index), ret = 0;
    conditionReader(cmdTemp, index);
        while(check()) {
            ret = p->strPrsTarget(cmdTemp, index + endLine, "}");
        }
        delete p;
        return ret;
}

int LoopCommand::enterKey(vector<string> vector, int index){
    int i = 0;
    while(vector.at(index + i) != "\n") {
        i++;
    }
    return i;
}

LoopCommand::LoopCommand(string type) {
    this->type = type;
}

LoopCommand::~LoopCommand() = default;


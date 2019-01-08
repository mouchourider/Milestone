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
#include "IfCommand.h"


int IfCommand::execute(vector<string> cmdTemp, int index){
    Parser* p = new Parser();
    int endLine = enterKey(cmdTemp, index), ret = 0;
    conditionReader(cmdTemp, index);
    if(check()) {
        ret = p->strPrsTarget(cmdTemp, index + endLine, "}");
    }
    return ret;
}

int IfCommand::enterKey(vector<string> vector, int index){
    int i = 0;
    while(vector.at(index + i) != "\n") {
        i++;
    }
    return i;
}

IfCommand::IfCommand() = default;

IfCommand::~IfCommand() = default;

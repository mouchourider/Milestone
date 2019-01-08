#include <iostream>
#include <fstream>
#include <string>
#include "Lexer.h"
#include "Parser.h"
#include "Command.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include <sys/socket.h>
using namespace std;

/*************************************************************************************
* Function name: main
* Input: none
* Output: none
* Function Operation: Gets as argument a string which is a location of a script to run.
**************************************************************************************/

int main (int argc, char **argv) {
    Parser* p = new Parser();
    Lexer* l = new Lexer();
    vector<string> stringVec;
    ifstream infile(argv[1]);
    stringVec = l->fileLexer(infile);
    p->strPrs(stringVec);
    infile.close();
    delete p;
    delete l;
    return 0;
}

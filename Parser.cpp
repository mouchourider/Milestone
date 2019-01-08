#include "Command.h"
#include "Parser.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "VarCommand.h"
#include "PrintCommand.h"
#include "LoopCommand.h"
#include "GlobalTables.h"
#include "ChangeCommand.h"
#include "ConditionParser.h"
#include "SleepCommand.h"
#include "PrintCommand.h"
#include "IfCommand.h"
#include "EnterCommand.h"
#include <string>
#include <map>


void Parser::strPrs(vector<string> cmdLines) {
    vector<string> cmdTemp;
    map<string,Command*> mapTmp;
    mapTmp = this->mapCmd;
    string temp;
    Command *c;
    GlobalTables* g = new GlobalTables();
    for(int i = 0; i < (int)(cmdLines.size()); i++) {
        string tmp((cmdLines.at(i)).c_str());
        if(g->keyExists(tmp)) {
            c = mapTmp["change"];
            i += c->execute(cmdLines, i);
        }
        else if(cmdLines.at(i) != "\n" && cmdLines.at(i) != "}"){
            c = mapTmp[cmdLines.at(i)];
            i += c->execute(cmdLines, i);
        }
    }
    delete g;
endSignal = true;
}

int Parser::strPrsTarget(vector<string> cmdLines, int start, string stop) {
    vector<string> cmdTemp;
    map<string, Command *> mapTmp;
    mapTmp = this->mapCmd;
    string temp;
    Command *c;
    int i = 0;
    GlobalTables *g = new GlobalTables();
    for (i = start + 1; cmdLines.at(i) != stop; i++) {
        string tmp((cmdLines.at(i)).c_str());
        if (g->keyExists(tmp)) {
            c = mapTmp["change"];
            i += c->execute(cmdLines, i);
        } else if (cmdLines.at(i) != "\n") {
            c = mapTmp[cmdLines.at(i)];
            i += c->execute(cmdLines, i);
        }
    }
delete g;
    return i - start;
}

Parser::Parser() {
    this->mapCmd[string("openDataServer")] = new OpenServerCommand();
    this->mapCmd[string("while")] = new LoopCommand("while");
    this->mapCmd[string("connect")] = new ConnectCommand();
    this->mapCmd[string("var")] = new VarCommand();
    this->mapCmd[string("print")] =  new PrintCommand();
    this->mapCmd[string("change")] = new ChangeCommand();
    this->mapCmd[string("sleep")] = new SleepCommand();
    this->mapCmd[string("if")] = new IfCommand();
    this->mapCmd[string("Enterc")] = new EnterCommand();
}

Parser::Parser(const Parser &) = default;

Parser::~Parser() {
    for (map<string, Command*>::iterator it = mapCmd.begin(); it != mapCmd.end(); ++it)
        delete it->second;
}

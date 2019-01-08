//
// Created by franckito on 12/18/18.
//
#include "Command.h"
#include "VarCommand.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include "GlobalTables.h"
#include <string.h>
#include "ConnectCommand.h"
#include "OpenServerCommand.h"
#include "ShuntingYard.h"
#include "Num.h"
#include <sys/socket.h>
#include <pthread.h>
#include <cmath>


/**
 * function name: execute
 * operation: execute a data
 * input: vector of strs commands, int index
 * @return int
 */
int VarCommand::execute(vector<string> cmdTemp, int index){
    if(strcmp("bind", cmdTemp.at(index + 3).c_str()) == 0){
        bind(cmdTemp.at(index + 1), cmdTemp.at(index + 4));
        return 4;
    }
    else if(strcmp("=", cmdTemp.at(index + 2).c_str()) == 0 && !is_expression(cmdTemp, index, enterKey(cmdTemp, index))) {
        bindSet(cmdTemp.at(index + 1), cmdTemp.at(index + 3));
        return 3;
    }
    else if((strcmp("=", cmdTemp.at(index + 2).c_str()) == 0) && is_expression(cmdTemp, index, enterKey(cmdTemp, index))){
        int end = enterKey(cmdTemp, index);
        bindSetExpression(cmdTemp.at(index + 1), cmdTemp, index, end);
        return end;
    }
    return 0;
}

/**
 * function name: bind
 * operation: binding
 * input: location and var strs
 * @return void
 */

void VarCommand::bind(string var, string location) {
    /* Send message to the server */
    string newLoc = location.substr(1,location.length()-2);
    double newVar = symbolServer.at(newLoc);
    symbolTable.insert(pair<string, double> (var, newVar));
    symbolAddr.insert(pair<string, string> (var, newLoc));
    symbolReverse.insert(pair<string, double> (newLoc, newVar));
}
/**
 * function name: bindSet
 * operation: bind and set the value
 * input: str var and str key
 * @return void
 */

void VarCommand::bindSet(string var, string key) {
    ShuntingYard* sY = new ShuntingYard();
    GlobalTables* gT = new GlobalTables();
    double tempKey = 0;
    if(gT->keyExists(key)){
        tempKey = symbolTable.at(key);
    }
    else {
        tempKey = sY->calculate(key);
    }
    symbolTable.insert(pair<string, double> (var, tempKey));
    symbolAddr.insert(pair<string, string> (var , key));
    symbolReverse.insert(pair<string, double> (key, tempKey));
    delete sY;
    delete gT;
}
/**
 * function name: bindSetExpression
 * operation: bind an expression
 * input: vector of strs commands, int and str of var
 * @return void
 */

void VarCommand::bindSetExpression(string var, vector<string> cmdTemp, int index, int end) {
    string expression = vectorToString(cmdTemp, index + 3, end);
    ShuntingYard* sY = new ShuntingYard();
    double newVal = sY->calculate(expression);
    symbolTable.insert(pair<string, double> (var, newVal));
}
/**
 * function name: enterKey
 * operation: enter a key
 * input: vector of strs commands, int and str
 * @return int
 */

int VarCommand::enterKey(vector<string> vector, int index){
    int i = 0;
    while(vector.at(index + i) != "\n") {
        i++;
    }
    return i;
}

/**
 * function name: is_expression
 * operation: check if the input is expression
 * input: vector of strs commands, inegers indexs
 * @return bool
 */

bool VarCommand::is_expression(vector<string> cmdTemp, int index, int end)
{
    int i = 0, j = 0;
    while(i < end){
        string temp = cmdTemp.at(i);
        vector<string> savedVal = GlobalTables::retKeys();
        repExistingVal(savedVal, temp);
        while(temp[j]){
            if(isalpha(temp[j])) {
                return false;
            }

            else if(temp[j] != '/' || temp[j] != '*' || temp[j] != '+' || temp[j] != '-' || temp[j] != '.' || temp[j] != '(' || temp[j] != ')' || !isdigit(temp[j])) {
                return false;
            }
            else {
                j++;
            }
        }
        i++;
    }
    return true;
}


VarCommand::VarCommand() {}

string VarCommand::vectorToString(vector<string> vector, int index, int end) {
    string ret = vector.at(index);
    int i = 1;
    while(i < end){
        ret += vector.at(index + i);
    }
    return ret;
}
/**
 * function name: repExistingVal
 * operation: replace a string val
 * input: vector of strs commands, and str
 * @return void
 */
void VarCommand::repExistingVal(vector<string> vector, string expression) {
    size_t index = 0;
    int i = 0;
    while (i < (int)(vector.size())) {
        /* Locate the substring to replace. */
        while (index != std::string::npos) {
            index = expression.find(vector.at(i), index);
            if (index == std::string::npos) { break; }

                /* Make the replacement. */
            else {
                string temp2 = expression.substr(index + vector.at(i).length(), expression.length());
                expression.replace(index, to_string(symbolTable.at(vector.at(i))).length(), to_string((symbolTable.at(vector.at(i)))));
                string temp1 = expression.substr(0, index + to_string(symbolTable.at(vector.at(i))).length());
                expression = temp1 + temp2;
                /* Advance index forward so the next iteration doesn't pick it up as well. */
                index += to_string(symbolTable.at(vector.at(i))).length();
            }
        }
        i++;
    }
}

VarCommand::~VarCommand() = default;

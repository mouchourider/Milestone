//
// Created by franckito on 12/19/18.
//

#include "ChangeCommand.h"
#include "ConnectCommand.h"
#include "GlobalTables.h"
#include <map>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "ShuntingYard.h"
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>

/**
 * function name: execute
 * operation: find the assign operation
 * input: vector of strings and index
 * @return int value
 */
int ChangeCommand::execute(vector<string> cmdTemp, int index) {
    int newLine = enterKey(cmdTemp, index);
    if(strcmp("=", cmdTemp.at(index + 1).c_str()) == 0) {
        string expression = vectorToString(cmdTemp, index + 2, index + newLine);
        ShuntingYard* sY = new ShuntingYard();
        changeData(cmdTemp.at(index), to_string(sY->calculate(expression)));
        delete sY;
    }
    else{
        printf("Error parser");
    }
        return newLine;
}
/**
 * function name: changeData
 * operation: change data at index
 * input: strings
 * @return int value
 */
void ChangeCommand::changeData(string var, string value) {
    string address = symbolAddr.at(var);
    value = to_string(atoi(value.c_str()));
    symbolTable.at(var) = stod(value);
    newOrder = "set " + address + " " + value + "\r\n";
}
/**
 * function name: enterKey
 * operation: enter a key func
 * input: vec of strings and index
 * @return int value
 */
int ChangeCommand::enterKey(vector<string> vec, int index){
    int i = 0;
    while(vec.at(index + i) != "\n") {
        i++;
    }
    return i;
}
/**
 * function name: vectorToString
 * operation: convert vec to str
 * input: vec of strings and index
 * @return string
 */
string ChangeCommand::vectorToString(vector<string> vector, int index, int end) {
    string ret = vector.at(index) + " ";
    int i = 1;
    while(index + i < end){
        if(ret.length() > 1)
        ret += vector.at(index + i) + " ";
        else {
            break;
        }
        i++;
    }
    return ret;
}


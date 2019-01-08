//
// Created by franckito on 12/20/18.
//
#include "ConditionParser.h"
#include "GlobalTables.h"
#include "ShuntingYard.h"


/**
 * function name: conditionReader
 * operation: read and parse condition
 * input: vec of strings and index
 * @return int
 */
int ConditionParser::conditionReader(vector<string> cmdLines, int index){
    int posOp = opCheck(cmdLines, index);
    int endLine = enterKey(cmdLines, index);
    string temp1 = vectorToString(cmdLines, index + 1, posOp - 1);
    string temp2 = vectorToString(cmdLines, index + posOp + 1, endLine - posOp - 2);


    this->a = temp1;
    this->op = cmdLines.at(index + posOp);
    this->b = temp2;
    return endLine;
}
/**
 * function name: check
 * operation: check keys and calculate
 * input: none
 * @return boolean
 */
bool ConditionParser::check(){
    ShuntingYard* sY = new ShuntingYard();
    GlobalTables* gT = new GlobalTables();
    double temp1 = 0, temp2 = 0;
    if(gT->keyExists(a)) {
        temp1 = symbolTable.at(a);
    } else
        temp1 = sY->calculate(a);

    if(gT->keyExists(b)) {
        temp2 = symbolTable.at(b);
    } else
        temp2 = sY->calculate(b);
    delete sY;
    delete gT;
    if(op == "!="){
        if(temp1 != temp2){
            return  true;
        }
        else
            return false;
    }
    else if(op == "=="){
        if(temp1 == temp2){
            return  true;
        }
        else
            return false;

    }
    else if(op == ">="){
        if(temp1 >= temp2){
            return  true;
        }
        else
            return false;
    }
    else if(op == "<="){
        if(temp1 <= temp2){
            return  true;
        }
        else
            return false;

    }
    else if(op == "<"){
        if(temp1 < temp2){
            return  true;
        }
        else
            return false;

    }
    else if(op == ">"){
        if(temp1 > temp2){
            return  true;
        }
        else
            return false;
    }
    return false;
}

/**
 * function name: execute
 * operation: execute data
 * input: vec of strs and index
 * @return int val
 */
int ConditionParser::execute(vector<string> cmdTemp, int index) {
    return 0;
}

/**
 * function name: opCheck
 * operation: check keys and calculate
 * input: vec of strs and index
 * @return int val
 */

int ConditionParser::opCheck(vector<string> vector, int index) {
    int i = 0;
    string s = vector.at(index);
    while(s != ">" && s != "<" && s != "<=" && s != ">=" && s != "==" && s != "!=") {
        s = vector.at(index + i);
        i++;
    }
    return i - 1;
}
/**
 * function name: vectorToString
 * operation: convert vector to string
 * input: vec of strs and index
 * @return string val
 */
string ConditionParser::vectorToString(vector<string> vector, int index, int end) {
    string ret = vector.at(index);
    int i = 1;
    while(index + i < index + end){
        ret += vector.at(index + i);
        i++;
    }
    return ret;
}
/**
 * function name: enterKey
 * operation: enter a key
 * input: vec of strs and index
 * @return int val
 */
int ConditionParser::enterKey(vector<string> vector, int index) {
        int i = 0;
        while(vector.at(index + i) != "\n") {
            i++;
        }
        return i - 2;
    }





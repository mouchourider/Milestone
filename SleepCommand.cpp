//
// Created by newbuntu on 26/12/18.
//

#include "SleepCommand.h"
#include "ShuntingYard.h"
#include <stdio.h>
#include <pthread.h>
#include <thread>
#include <chrono>
#include <unistd.h>
using namespace std;

/**
 * function name: execute
 * operation: execute a data
 * input: vector of strs and index
 * @return int
 */

int SleepCommand::execute(vector<string> cmdTemp, int index) {
    ShuntingYard* sY = new ShuntingYard();
    int endLine = enterKey(cmdTemp, index);
    string temp = vectorToString(cmdTemp, index + 1, index + endLine);
    double time = sY->calculate(temp);
    sleep(time/1000);
    delete sY;
    return endLine;
}

/**
 * function name: vectorToString
 * operation: convert a vec to str
 * input: vector of strs and index
 * @return string
 */

string SleepCommand::vectorToString(vector<string> vector, int index, int end) {
    string ret = vector.at(index);
    int i = 1;
    while(index + i < end){
        ret += vector.at(index + i);
    }
    return ret;
}
/**
 * function name: enterKey
 * operation: enter a key
 * input: vector of strs and index
 * @return int
 */
int SleepCommand::enterKey(vector<string> vector, int index){
    int i = 0;
    while(vector.at(index + i) != "\n") {
        i++;
    }
    return i;
}


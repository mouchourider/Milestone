#ifndef FLIGHTGEARINTERPRETER_SHUNTINGYARD_H
#define FLIGHTGEARINTERPRETER_SHUNTINGYARD_H

#include <sstream>
#include <string.h>
#include <iostream>
#include <list>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <stdlib.h>
using namespace std;

class ShuntingYard {

public:

    static double calculate(string tokens);
    // static string checkNeg (string input);
private:

    static int precedence(char op);
    static double applyOp(double a, double b, char op);
};


#endif //FLIGHTGEARINTERPRETER_SHUNTINGYARD_H
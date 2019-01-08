//
// Created by einav on 26/12/18.
//

#ifndef FLIGHTGEAR_PROJECT_VAR_H
#define FLIGHTGEAR_PROJECT_VAR_H


#include "Expression.h"
using namespace std;

class Var : public Expression{

private:
    string name;

public:
    Var(string name);
    double calculate() override;
};


#endif //FLIGHTGEAR_PROJECT_VAR_H

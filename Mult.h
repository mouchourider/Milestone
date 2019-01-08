//
// Created by einav on 21/12/18.
//

#ifndef FLIGHTGEAR_PROJECT_MULT_H
#define FLIGHTGEAR_PROJECT_MULT_H


#include "BinaryExpression.h"

class Mult : public BinaryExpression {

public:
    Mult(Expression* leftExp, Expression* rightExp);

    double calculate() override;

    ~Mult();
};


#endif //FLIGHTGEAR_PROJECT_MULT_H

//
// Created by einav on 21/12/18.
//

#ifndef FLIGHTGEAR_PROJECT_DIV_H
#define FLIGHTGEAR_PROJECT_DIV_H


#include "BinaryExpression.h"

class Div: public BinaryExpression{
public:

    Div(Expression* leftExp, Expression* rightExp);

    double calculate()override;

    ~Div();
};


#endif //FLIGHTGEAR_PROJECT_DIV_H

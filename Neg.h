#ifndef FLIGHTGEAR_PROJECT_NEG_H
#define FLIGHTGEAR_PROJECT_NEG_H
#include "UnaryExpression.h"

class Neg : public UnaryExpression {

public:

    Neg(Expression* e);

    Neg(double num);

    double calculate()override;
};


#endif //FLIGHTGEAR_PROJECT_NEG_H

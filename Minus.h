#ifndef FLIGHTGEAR_PROJECT_MINUS_H
#define FLIGHTGEAR_PROJECT_MINUS_H
#include "Expression.h"
#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:

    Minus(Expression *leftExp, Expression *rightExp);

    double calculate() override;

    ~Minus();
};


#endif //FLIGHTGEAR_PROJECT_MINUS_H

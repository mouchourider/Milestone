#include <map>
#include "BinaryExpression.h"
#include "Expression.h"
#include "Minus.h"
#include "Num.h"
#include "Neg.h"

Minus:: Minus (Expression *leftExp, Expression *rightExp) :
    BinaryExpression(leftExp,rightExp) {}


double Minus::calculate() {
    return getLeftExp()->calculate() -
                getRightExp()->calculate();
}

Minus::~Minus() = default;

#include <map>
#include "BinaryExpression.h"
#include "Expression.h"
#include "Plus.h"
#include "Num.h"

Plus::Plus(Expression *leftExp, Expression *rightExp) :
        BinaryExpression(leftExp, rightExp){}

double Plus::calculate() {
    return getLeftExp()->calculate() +
            getRightExp()->calculate();
}

Plus::~Plus() = default;

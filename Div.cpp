
#include "Expression.h"
#include "BinaryExpression.h"
#include "Div.h"
#include "Num.h"
#include <map>
#include "Minus.h"
#include "Mult.h"

//Instantiates a new Div.
 Div::Div(Expression* leftExp, Expression* rightExp) :
    BinaryExpression(leftExp, rightExp){}

double Div::calculate() {
        return getLeftExp()->calculate() / getRightExp()->calculate();
}

Div::~Div() = default;


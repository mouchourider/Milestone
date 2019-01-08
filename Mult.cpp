
#include "Expression.h"
#include "Mult.h"
#include "BinaryExpression.h"
#include "Num.h"
#include "Plus.h"
#include <map>

//Instantiates a new Mult.
 Mult:: Mult(Expression* leftExp, Expression* rightExp):
         BinaryExpression(leftExp, rightExp){}

double Mult:: calculate(){
        return getLeftExp()->calculate() * getRightExp()->calculate();
}

Mult::~Mult() = default;

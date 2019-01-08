#include "Neg.h"
#include <map>
#include "UnaryExpression.h"
#include "Expression.h"
#include "BinaryExpression.h"
#include "Num.h"
#include "Plus.h"


Neg:: Neg(Expression* e) :
    UnaryExpression(e){}

Neg:: Neg(double num) :
    UnaryExpression(new Num(num)){}

double Neg:: calculate(){
        if (UnaryExpression::getExpression()->calculate() == 0) {
            return 0;
        }
        return (-1) * getExpression()->calculate();
}


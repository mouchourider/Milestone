//
#include <map>
#include <string>
#include <list>
#include <vector>
#include <string.h>
#include "Expression.h"
#include "BinaryExpression.h"
using namespace std;

BinaryExpression::BinaryExpression(Expression* leftExp, Expression* rightExp) {
    this->leftExp = leftExp;
    this->rightExp = rightExp;
}


 //Gets left exp.
Expression* BinaryExpression::getLeftExp() {
    return leftExp;
}

 //Gets right exp.
Expression* BinaryExpression::getRightExp() {
    return rightExp;
}

BinaryExpression::BinaryExpression() = default;

BinaryExpression::~BinaryExpression() = default;

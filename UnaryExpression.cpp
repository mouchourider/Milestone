//
// Created by einav on 23/12/18.
//

#include "Expression.h"
#include "UnaryExpression.h"
#include <map>
#include <string>
#include <list>
#include <vector>
#include <string.h>
using namespace std;

UnaryExpression:: UnaryExpression(Expression* expression1) {
this->expression = expression1;
}

//Gets expression.
Expression* UnaryExpression:: getExpression() {
    return this->expression;
}

UnaryExpression::UnaryExpression() {}

UnaryExpression::~UnaryExpression() = default;

#ifndef UNTITLED1_UNARYEXPRESSION_H
#define UNTITLED1_UNARYEXPRESSION_H
#include <map>
#include <string>
#include <list>
#include <vector>
#include <string.h>
#include "Expression.h"
using namespace std;

//The type Unary expression.
class UnaryExpression: public Expression {


    Expression* expression;


//Instantiates a new Unary expression.
public:

    UnaryExpression(Expression* expression1);


    //Gets expression.
    Expression* getExpression();

    UnaryExpression();

    ~UnaryExpression();
};

#endif //UNTITLED1_UNARYEXPRESSION_H
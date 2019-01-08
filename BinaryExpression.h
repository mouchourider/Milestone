
#ifndef UNTITLED1_BINARYEXPRESSION_H
#define UNTITLED1_BINARYEXPRESSION_H
#include <map>
#include <string>
#include <list>
#include <vector>
#include <string.h>
#include "Expression.h"
using namespace std;

//The type Binary expression.
class BinaryExpression : public Expression {

//Instantiates a new Binary expression.
protected:
    Expression* rightExp;
    Expression* leftExp;
public:
    BinaryExpression(Expression* leftExp, Expression* rightExp);

    BinaryExpression();

    Expression* getLeftExp();

    Expression* getRightExp();

    ~BinaryExpression();
};

#endif //UNTITLED1_BINARYEXPRESSION_H

#ifndef UNTITLED1_PLUS_H
#define UNTITLED1_PLUS_H
#include <map>
#include "BinaryExpression.h"
#include "Expression.h"

class Plus : public BinaryExpression {

    //Instantiates a new Plus.
public:

    Plus(Expression* leftExp,Expression* rightExp);

    double calculate() override;

    ~Plus();
};



#endif //UNTITLED1_PLUS_H
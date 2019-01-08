
#ifndef UNTITLED1_NUM_H
#define UNTITLED1_NUM_H
#include <map>
#include "BinaryExpression.h"
#include "UnaryExpression.h"
#include "Expression.h"
#include <sstream>

class Num : public Expression {

    double num;
    string str;

//Instantiates a new num.
public:

    Num(double number);
    Num(string str);
    //Evaluate the expression using the variable values provided. in the
    //assignment, and return the result. If the expression contains a variable
    //which is not in the assignment, an exception is thrown.
    double calculate() override;

    ~Num();
};

#endif //UNTITLED1_NUM_H
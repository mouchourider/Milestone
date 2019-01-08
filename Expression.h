#ifndef UNTITLED1_EXPRESSION_H
#define UNTITLED1_EXPRESSION_H

#include <map>
#include <string>
#include <vector>
using namespace std;

 //The interface Expression.

class Expression {
public:
    //Evaluate double.
    // Evaluate the expression using the variable values provided
    // in the assignment, and return the result.  If the expression
    // contains a variable which is not in the assignment, an exception
    // is thrown.
    virtual double calculate() {
        return 0;
    }


};
#endif //UNTITLED1_EXPRESSION_H
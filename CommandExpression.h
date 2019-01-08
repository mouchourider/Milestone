//
// Created by newbuntu on 24/12/18.
//

#ifndef UNTITLED1_COMMANDEXPRESSION_H
#define UNTITLED1_COMMANDEXPRESSION_H

#include "Command.h"
#include "Expression.h"
class CommandExpression: public Command {
    Expression* e;
public:

    int execute(vector<string> cmdTemp, int index) override;

    CommandExpression(Expression* e);
};

#endif //UNTITLED1_COMMANDEXPRESSION_H

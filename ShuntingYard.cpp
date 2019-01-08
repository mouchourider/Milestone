#include "ShuntingYard.h"
#include "string.h"
#include "Num.h"
#include "Expression.h"
#include "GlobalTables.h"
#include<iostream>
#include<cctype>
#include<stack>
#include <bits/stdc++.h>

using namespace std;

// CPP program to calculate a given
// expression where tokens are
// separated by space.

// Function to find precedence of
// operators.
int ShuntingYard:: precedence(char op){
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    return 0;
}

// Function to perform arithmetic operations.
double ShuntingYard:: applyOp(double a, double b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}


double ShuntingYard:: calculate(string tokens){
    int i;
    GlobalTables* globalT=new GlobalTables();

    // stack to store integer values.
    stack <double> values;

    // stack to store operators.
    stack <char> ops;

    string variable = "";

    for(i = 0; i < (int)(tokens.length()); i++){

        if(tokens[0]=='-' && tokens[1]=='-'){

            tokens = tokens.substr(2,tokens.length());
        }

        else if((tokens[0]=='-' && isdigit(tokens[1])) ||
                (tokens[0]=='-' && tokens[1]!='-'&&tokens[1]!='*'
                 &&tokens[1]!='/'&&tokens[1]!='+'
                 &&tokens[1]!='('&&tokens[1]!=' ')){

            int keep=i;
            tokens = tokens.insert(i, "(0");
            while(tokens[i+3]!='('&&tokens[i+3]!=')'&&
                  tokens[i+3]!='-'&& tokens[i+3]!='+'
                  &&tokens[i+3]!='*'&&tokens[i+3]!='/'&&tokens[i+3]!='\0'){
                i++;
            }
            tokens=tokens.insert(i+3,")");
            i=keep-1;
            continue;
        }
            //is a variable
        else if(!isdigit(tokens[i])&& tokens[i]!='-'&&tokens[i]!='*'
                &&tokens[i]!='/'&&tokens[i]!='+'&&tokens[i]!='('
                &&tokens[i]!=' '&&tokens[i]!=')'&&tokens[i]!='\0'){

            while(tokens[i] !='-'&&tokens[i]!='*'&&tokens[i]!='/'&&
                  tokens[i]!='+'&&tokens[i]!='('&&tokens[i]!=' '
                  &&tokens[i]!=')'&&tokens[i]!='\0'){
                variable+=tokens[i];
                i++;
            }

            if(globalT->keyExists(variable)){
                double value = globalT->getVal(variable);
                values.push(value);
                variable="";
            }
        }

        // Current token is a whitespace,
        // skip it.
        if(tokens[i] == ' ')
            continue;

            // Current token is an opening
            // brace, push it to 'ops'
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }

            // Current token is a number, push
            // it to stack for numbers.
        else if(isdigit(tokens[i])){
            double val = 0;

            // There may be more than one
            // digits in number.
            while(i < (int)(tokens.length()) &&
                  isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
            i--;
            values.push(val);
        }

            // Closing brace encountered, solve
            // entire brace.
        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                double val2 = values.top();
                values.pop();

                double val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // pop opening brace.
            ops.pop();
        }


        else
        {
            if(tokens[i]=='-'&& (tokens[i-1]=='-'||tokens[i-1]=='*'
                                 ||tokens[i-1]=='/'||
                                 tokens[i-1]=='+'||tokens[i-1]=='(')){
                int keep=i;
                tokens = tokens.insert(i, "(0");
                while(tokens[i+3]!='('&&tokens[i+3]!=')'
                      &&tokens[i+3]!='-'&& tokens[i+3]!='+'
                      &&tokens[i+3]!='*'&&tokens[i+3]!='/'
                      &&tokens[i+3]!='\0'){
                    i++;
                }
                tokens=tokens.insert(i+3,")");
                i=keep-1;
                continue;
            }
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while(!ops.empty() && precedence(ops.top())
                                  >= precedence(tokens[i])){
                double val2 = values.top();
                values.pop();

                double val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while(!ops.empty()&&ops.top()!='\0'){
        double val2 = values.top();
        values.pop();

        double val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    // Top of 'values' contains result, return it.
    delete globalT;
    return values.top();
}













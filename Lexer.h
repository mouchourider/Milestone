#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Lexer {
        public:
        Lexer();          // public constructor
        ~Lexer();
        Lexer(const Lexer&);  // public copy constructor
        vector<string> fileLexer(ifstream& ifs);
};

#endif

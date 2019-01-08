#include "Command.h"
#include "Lexer.h"
#include <fstream>


vector<string> Lexer::fileLexer(ifstream& infile) {
    int index = 0, beg = 0;
    vector<string> tempVec; //Initialise vector where we'll insert our strings
    string script( (istreambuf_iterator<char>(infile) ),(istreambuf_iterator<char>()) ); //Puts all contents of the file in string script
    for(char& c : script) {
        if(isspace(c) != 0 || c == '\n') {
            string tempStr = "";
            try {
                if(c == '\n') {
                    tempStr = script.substr(beg, index - beg);
                    tempVec.push_back(tempStr);
                    tempVec.push_back("\n");
                }
                else {
                    tempStr = script.substr(beg, index - beg); //Create substring from index 'beg' to the location of next endline char
                    if(tempStr != "")
                        tempVec.push_back(tempStr); //Pushes in the vector the substring we created
                        beg += (index - beg) + 1 ;
                }
            }
            catch(std::out_of_range){
                printf("End of array");
                return tempVec;
            }
            beg += (index - beg) + 1 ;
        }
    index ++;
    }
 return tempVec;
}

Lexer::Lexer() = default;

Lexer::~Lexer() = default;

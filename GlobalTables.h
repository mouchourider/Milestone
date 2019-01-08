//
// Created by franckito on 12/19/18.
//

#ifndef UNTITLED1_GLOBALTABLES_H
#define UNTITLED1_GLOBALTABLES_H
#include <map>
#include <string>
#include <vector>
using  namespace std;


extern map<string, double> symbolTable;
extern map<string, double> symbolServer;
extern map<string, string> symbolAddr;
extern map<string, double> symbolReverse;
extern vector<string> tableOrder;
extern string newOrder;
extern bool endSignal;
extern bool runClient;
extern pthread_mutex_t connectLock;

class GlobalTables {
public:
    GlobalTables();
    bool addrExists(string seek);
    static vector<string> retKeys();
    double getVal(string val);
    string getValues();
    bool keyExists(string seek);
    bool revExists(string seek);
};

#endif //UNTITLED1_GLOBALTABLES_H
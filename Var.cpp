//
// Created by einav on 26/12/18.
//

#include "Var.h"
#include "GlobalTables.h"

Var::Var(string name){
    this->name=name;
}

double Var::calculate() {
    GlobalTables* globalT=new GlobalTables();
    if(globalT->keyExists(name)){
        double v =globalT->getVal(name);
        return v;
    }
    return 0;
}

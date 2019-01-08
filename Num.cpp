
#include "Num.h"

Num::Num(double number) {
    this->num = number;
}

double Num::calculate() {
    return this->num;
}

Num::Num(string str1) {
    this->str=str1;
}

Num::~Num() = default;

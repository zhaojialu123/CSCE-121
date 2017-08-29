#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "std_lib_facilities_4.h"
#include "Token_stream.h"

class Calculator{
public:
    Calculator(){}; 
    double calculate_total(string input); // calculate expression
private:
    double expression(); // expression member
    double fact();       //factorial operators
    double primary();    //+/- signs
    double term();       //calculate terms
    double factorial(double n); // helper factorial function
    Token_stream ts;     // internal token stream
};

#endif
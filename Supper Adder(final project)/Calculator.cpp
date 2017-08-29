#include "Calculator.h"

double Calculator::calculate_total(string input)
{
    ts = Token_stream(input);
    return expression();
}

double Calculator::factorial(double n) //compute factorial of n return 0 for values greater than 9
{
    if(n > 9)
        return 0;
    
    int total = 1;

    for(int i = 1; i <= n; i++)
        total *= i;

    return total;
}

double Calculator::primary() // read and evaluate a Primary
{
	cout<<"primary\n";
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') return 0;
            return d;
        }
    case '+': // Deal with preceding signs
        return primary();
    case '-': // Deal with negative preceding sign
        return -primary();
    case '8':            // we use '8' to represent a number
        return t.value;  // return the number's value
    case 'x':            // exit case
        ts.putback('x');
        return 0;
    }
	return 0;
}

double Calculator::fact() // deal with factorials
{
    double left = primary();
    Token t = ts.get();        

    while(true) {
		cout<<"fact\n";
        switch (t.kind) {
        case '!':
            left = factorial(left); // calculate factorial
            t = ts.get();
            break;
        case '8': throw logic_error("term expected"); 
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

double Calculator::expression() // read and evaluate a Expression
{
    double left = term();      
    Token t = ts.get();        

    while(true) {
        cout << "expression\n" << t.kind << endl;
        switch(t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default: 
            ts.putback(t);     // put t back into the token stream
            return left;       
        }
    }
}

double Calculator::term() // read and evaluate a Term
{
    double left = fact();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
		cout<<"term\n";
        switch (t.kind) {
        case '*':
            left *= primary(); // calculate multiply from primaries around division
            t = ts.get();
            break;
        case '/': // calculate division
            {
            double d = primary(); 
            if (d == 0) throw logic_error("divide by zero"); 
            left /= d; 
            t = ts.get();
            break;
            }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}
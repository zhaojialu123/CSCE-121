#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

#include "std_lib_facilities_4.h"

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

class Token_stream {
public: 
    Token_stream();   
    Token_stream(string instring); // make a Token_stream that reads from a stringstream
    Token get();      
    void putback(Token t);    
private:
    istream* stream;
    bool full;        
    Token buffer;     
};

#endif
#include "Token_stream.h"

Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
    stream = &cin;
}

Token_stream::Token_stream(string instring)
:full(false), buffer(0)    // no Token in buffer
{
    stream = new stringstream(instring);
}


void Token_stream::putback(Token t)
{
    if (full) throw std::logic_error("full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) { 
        full=false; 
        return buffer;
    }
    char ch;
    *stream >> ch;    
    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': case '!':
        return Token(ch);      
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            stream->putback(ch);         // put digit back into the input stream
            double val;
            *stream >> val;              // read a floating-point number
            return Token('8',val);       // let '8' represent "a number"
        }
    default: throw std::logic_error("Bad Token");
    }
}
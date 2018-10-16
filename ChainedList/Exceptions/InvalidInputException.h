//
// Created by schreiner.andreas on 13.09.2018.
//

#ifndef CHAINEDLIST_INVALIDINPUTEXCEPTION_H
#define CHAINEDLIST_INVALIDINPUTEXCEPTION_H
#include <exception>
#include <string>

using namespace std;

class InvalidInputException : exception {
private:
    string exString ="";
public:
    virtual const char* what() const throw()
    {
        return exString.c_str();
    }
    InvalidInputException(string s) : exception(){
        exString = s;
    };

};


#endif //CHAINEDLIST_INVALIDINPUTEXCEPTION_H

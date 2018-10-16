//
// Created by schreiner.andreas on 13.09.2018.
//

#ifndef CHAINEDLIST_OBJECTNOTEXISTINGEXCEPTION_H
#define CHAINEDLIST_OBJECTNOTEXISTINGEXCEPTION_H
#include <exception>
#include <string>

using namespace std;

class ObjectNotExistingException : exception {
private:
    string exString ="";
public:
    virtual const char* what() const throw()
    {
        return exString.c_str();
    }
    ObjectNotExistingException(string s) : exception(){
        exString = s.c_str();
    };
};
#endif //CHAINEDLIST_OBJECTNOTEXISTINGEXCEPTION_H

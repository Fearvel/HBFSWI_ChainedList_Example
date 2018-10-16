//
// Created by schreiner.andreas on 12.09.2018.
//

#ifndef CHAINEDLIST_OBJECTEXISTSEXCEPTION_H
#define CHAINEDLIST_OBJECTEXISTSEXCEPTION_H
#include <exception>
#include <string>

using namespace std;

class ObjectExistsException : exception {
private:
    string exString ="";
public:
    virtual const char* what() const throw()
    {
        return exString.c_str();
    }
    ObjectExistsException(string s) : exception(){
        exString = s.c_str();
    };
};
#endif //CHAINEDLIST_OBJECTEXISTSEXCEPTION_H

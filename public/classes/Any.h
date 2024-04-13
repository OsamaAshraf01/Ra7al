//
// Created by OSAMA ASHRAF on 4/13/2024.
//
/*==============Example==============
    Any x;
    x = 5;
    x = 14.7;
    x = "Osama";
    cout<<x;
 =====================================*/
#ifndef RA7AL_ANY_H
#define RA7AL_ANY_H
#include <iostream>
#include <variant>
#include <string>
#include <sstream>
using namespace std;
using Variant = variant<int, double, string, char>;

class Any : public Variant{
private:
    string toString();
public:
    using Variant::variant;   // bringing all variant's constructors
    friend class List;


    /// Operators
    friend ostream& operator <<(ostream& os, Any& x){cout<<x.toString(); return os;}
};


#endif //RA7AL_ANY_H

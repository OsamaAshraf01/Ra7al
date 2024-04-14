//
// Created by OSAMA ASHRAF on 4/11/2024.
/*===========Example================
 // With Constructor

 // Assigning value by value
 Case c;
 c.header = {"Name", "Age"};
 c["Name"] = "Osama";
 c["Age"] = 19;

 cout << c;
*/

#ifndef RA7AL_CASE_H
#define RA7AL_CASE_H
#include "../../public/classes/List.h"
#include "../../public/functions.h"
#include <unordered_map>

using namespace std;

class Case {
public:
    List header;
    unordered_map<string, Any> dict;
    // TODO: Add Constructor

    void print();

    Any& operator [](string index){return dict[index];}    // (&) to enable assigning values
    friend ostream& operator <<(ostream& os, Case& c){c.print(); return os;}
};


#endif //RA7AL_CASE_H

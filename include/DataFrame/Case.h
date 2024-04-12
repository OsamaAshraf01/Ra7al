//
// Created by OSAMA ASHRAF on 4/11/2024.
//

#ifndef RA7AL_CASE_H
#define RA7AL_CASE_H
#include "../../public/classes.h"
#include "../../public/functions.h"
#include <bits/stdc++.h>
#define any variant<int, double, string, char>

using namespace std;

class Case {
public:
    map<string, any> dict;

    void print();
};


#endif //RA7AL_CASE_H

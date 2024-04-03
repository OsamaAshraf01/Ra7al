//
// Created by OSAMA ASHRAF on 4/3/2024.
//

#ifndef RA7AL_PUBLICFUNCTIONS_H
#define RA7AL_PUBLICFUNCTIONS_H

#include <bits/stdc++.h>
using namespace std;

vector<string> split(string& str, char delimiter) {
    vector<string> result;
    string temp;
    for (char i : str) {
        if (i == delimiter) {
            result.push_back(temp);
            temp = "";
        } else {
            temp += i;
        }
    }
    result.push_back(temp);
    return result;
}

#endif //RA7AL_PUBLICFUNCTIONS_H

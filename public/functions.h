//
// Created by OSAMA ASHRAF on 4/3/2024.
//

#ifndef RA7AL_FUNCTIONS_H
#define RA7AL_FUNCTIONS_H
#include <bits/stdc++.h>
using namespace std;

// A function to split a string based on specific delimiter (space by default)
static vector<string> split(string &str, char delimiter = ' ');


// A function to join vector of string values by a delimiter
static string join(vector<string> &values, const string &delimiter);


// A function to print a vector
template <typename T>
static void printVec(vector<T> v);













///==========================================================
///========================Definition========================
///==========================================================
vector<string> split(string &str, char delimiter)
{
    vector<string> result;
    string temp;
    for (char i : str)
    {
        if (i == delimiter)
        {
            result.push_back(temp);
            temp = "";
        }
        else
        {
            temp += i;
        }
    }
    result.push_back(temp);
    return result;
}


string join(vector<string> &values, const string &delimiter)
{
    ostringstream oss;
    for (int i = 0; i < values.size(); i++)
        oss << values[i] << (i + 1 != values.size() ? delimiter : "");

    return oss.str();
}


template <typename T>
void printVec(vector<T> v){
    cout<<'{';
    for(int i=0 ; i<v.size() ; i++)
        cout<<v[i]<<(i < v.size()-1 ? ", " : "");
    cout<<"}\n";
}

#endif // RA7AL_FUNCTIONS_H

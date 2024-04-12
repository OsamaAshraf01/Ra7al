//
// Created by OSAMA ASHRAF on 3/25/2024.
//

#ifndef RA7AL_DATAFRAME_H
#define RA7AL_DATAFRAME_H
#include <bits/stdc++.h>
#include "Series.h"
#include "Case.h"
#define any variant<int, double, string, char>
using namespace std;


class DataFrame
{
private:
    string path;
    string primaryKey;
    List header;
    ofstream fout;
    ifstream fin;

//    vector<Series> columns;
    vector<Case> rows;
public:
    explicit DataFrame(string databasePath);
    void insert(Case);
    DataFrame select(string conditionColumn, any conditionValue);
    DataFrame update(string conditionColumn, any conditionValue, any newValue);
    DataFrame sortBy(string columnName, bool descending=false);
    void print();

    void save();
};

#endif // RA7AL_DATAFRAME_H

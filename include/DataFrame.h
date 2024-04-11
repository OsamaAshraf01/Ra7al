//
// Created by OSAMA ASHRAF on 3/25/2024.
//

#ifndef RA7AL_DATAFRAME_H
#define RA7AL_DATAFRAME_H
#include <bits/stdc++.h>
using namespace std;


class Database
{
private:
    string path;
    string primaryKey;
    ofstream fout;
    ifstream fin;

    vector<Series> columns;
    vector<Case> rows;
public:
    explicit Database(string databasePath);
    void insert(vector<string> values);
    void select(vector<string> columns);
    void update(vector<string> columns, vector<string> values, vector<string> condition);


};

#endif // RA7AL_DATAFRAME_H

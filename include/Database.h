//
// Created by OSAMA ASHRAF on 3/25/2024.
//

#ifndef RA7AL_DATABASE_H
#define RA7AL_DATABASE_H
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Database {
private:
    string path;

    Database(); // To prevent creating an object without a database path
public:
    Database(string databasePath);
    void insert(vector<string> values);
    void select(vector<string> columns);
    void update(vector<string> columns, vector<string> values, vector<string> condition);
};


#endif //RA7AL_DATABASE_H

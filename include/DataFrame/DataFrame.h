//
// Created by OSAMA ASHRAF on 3/25/2024.
/*=============Example=============
 DataFrame d("../data/flights.csv");
 DataFrame df1 = d.SELECT({"Origin Airport"}, {"Cairo International Airport"});
 cout<<df1;

 ==================
 DataFrame df2 = d.SELECT({"Departure Date", "Airline"}, {"15-04-2024", "Nile Air"});
 cout<<df2;

 ==================
 df3 = d.SELECT({"Price"}, {400}, [](Any a, Any b){return a >= b;}) // To get flights with price >= 400

 ==================
 d.UPDATE("Origin Airport", "Cairo International Airport", "Origin Airport", "Osama International Airport");
 cout << d;

 ==================
 d.UPDATE("Origin Airport", "Cairo International Airport", "Origin Airport", "Osama International Airport", [](Any a, Any b){return a < b;});
 cout << d;

 ==================
 cout << d[0];  // to print a single case in the DataFrame

 */
#ifndef RA7AL_DATAFRAME_H
#define RA7AL_DATAFRAME_H
#include <bits/stdc++.h>
//#include "Series.h"
#include "Case.h"

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
    // Constructors
    explicit DataFrame(string databasePath);
    explicit DataFrame(List& header);

    // Methods
    void INSERT(Case&);
    void UPDATE(string conditionColumn, Any conditionValue, string updateColumn, Any newValue, function<bool(Any, Any)> operation=[](Any a, Any b){return a == b;});
    DataFrame SELECT(vector<string> conditionColumns, vector<Any> conditionValues);
    DataFrame SortBy(string columnName, bool descending=false);
    void print();

    void save();
    List Header();



    // Operators
    friend ostream& operator <<(ostream& os, DataFrame& d){d.print(); return os;}
    Case& operator [](int index);
};

#endif // RA7AL_DATAFRAME_H

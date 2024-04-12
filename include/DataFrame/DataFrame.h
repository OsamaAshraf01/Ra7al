//
// Created by OSAMA ASHRAF on 3/25/2024.
/*=============Example=============
DataFrame d("../data/flights.csv");
DataFrame df1 = d.select({"Origin Airport"}, {"Cairo International Airport"});
cout<<df1;


DataFrame df2 = d.select({"Departure Date", "Airline"}, {"15-04-2024", "Nile Air"});
cout<<df2;



cout << d[0];  // to print a single case in the DataFrame

 */
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

    explicit DataFrame(List& header);
public:
    explicit DataFrame(string databasePath);
    void insert(Case&);
    DataFrame select(vector<string> conditionColumns, vector<any> conditionValues);
    DataFrame update(string conditionColumn, any conditionValue, any newValue);
    DataFrame sortBy(string columnName, bool descending=false);
    void print();

    void save();
    List Header();



    // Operators
    friend ostream& operator <<(ostream& os, DataFrame& d){d.print(); return os;}
    Case& operator [](int index);
};

#endif // RA7AL_DATAFRAME_H

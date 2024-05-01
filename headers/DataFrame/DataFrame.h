//
// Created by OSAMA ASHRAF on 3/25/2024.
/*=============Examples=============
 DataFrame d("../data/flights.csv");
 DataFrame df1 = d.SELECT({"Origin Airport"}, {"Cairo International Airport"});
 cout<<df1;

 ==================
 DataFrame df2 = d.SELECT({"Departure Date", "Airline"}, {"15-04-2024", "Nile Air"});
 cout<<df2;

 ==================
 df3 = d.SELECT({"Price"}, {400}, GREATER_OR_EQUAL) // To get flights with price >= 400

 ==================
 // Multiselect
 DataFrame x = d.SELECT({"Departure Date", "Price"}, {"18-04-2024", 350}, LESS_OR_EQUAL)
                .SELECT({"Origin Airport"}, {"Cairo International Airport"}, EQUAL);

 ==================
 d.UPDATE("Origin Airport", "Cairo International Airport", "Origin Airport", "Osama International Airport");
 cout << d;

 ==================
 d.UPDATE("Origin Airport", "Cairo International Airport", "Origin Airport", "Osama International Airport", LESS);
 cout << d;

 ==================
 cout << d[0];  // to print a single case in the DataFrame

 */
#ifndef RA7AL_DATAFRAME_H
#define RA7AL_DATAFRAME_H
#include <fstream>
#include <functional>
#include <sstream>
//#include "Series.h"
#include "Case.h"
#include "public/functions.h"
#include "config.h"
#include "mainwindow.h"

using namespace std;
#define EQUAL [](Any a, Any b){return a == b;}
#define GREATER [](Any a, Any b){return a > b;}
# define LESS [](Any a, Any b){return a < b;}
# define GREATER_OR_EQUAL [](Any a, Any b){return a >= b;}
# define LESS_OR_EQUAL [](Any a, Any b){return a <= b;}
# define NOT_EQUAL [](Any a, Any b){return a != b;}

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
    void UPDATE(string conditionColumn, Any conditionValue, string updateColumn, Any newValue, function<bool(Any, Any)> operation=EQUAL);
    DataFrame SELECT(vector<string> conditionColumns, vector<Any> conditionValues, function<bool(Any, Any)> operation=EQUAL);
    DataFrame SortBy(string columnName, bool descending=false);
    void print();

    void save();
    List Header();
    bool isEmpty();

    QString toQstring();



    // Operators
    friend ostream& operator <<(ostream& os, DataFrame& d){d.print(); return os;}
    Case& operator [](int index);
};

#endif // RA7AL_DATAFRAME_H

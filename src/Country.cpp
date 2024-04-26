// created by Ahmed Hamdy Kotp

#include "../headers/Country.h"
#include <iostream>
Country::Country()
{
}

Country::Country(string name)
{
}

void Country::initialize(const string &filename)
{
    X = CSVManager(filename);
    X.read();
}

void Country::setCountryinfo(const string &Countryname)
{
    name = Countryname;
}

void Country::PrintCountryInfo()
{
    initialize("../data/countries.csv");
    vector<vector<string>> data = X.read();

    for (vector<string> row : data)
    {
        if (row[0] == name)
        {
            cout << "Country Name: " << row[0] << endl;
            cout << "Population: " << row[1] << endl;
            cout << "Language: " << row[2] << endl;
            cout << "Capital City: " << row[3] << endl;
            cout << "Area: " << row[4] << " square kilometers" << endl;
            break;
        }
    }
}

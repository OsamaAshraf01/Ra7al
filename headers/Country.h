// Created by Ahmed Hamdy Kotp

#ifndef COUNTRY_H
#define COUNTRY_H
#include "../include/DataFrame/CSVManager.h"
#include <vector>
using namespace std;
#include <string>

class Country {
public:
    string name;
    long long population;
    string language;
    string capitalCity;
    double area;
    CSVManager X;
    Country();
    Country(string name);
    Country(string name, long long population, string language, string capitalCity, double area) :
        name(name), population(population), language(language), capitalCity(capitalCity), area(area) {}
    void initialize(const string& filename);
    void setCountryinfo(const string& Countryname);
    void PrintCountryInfo();
};

#endif // COUNTRY_H

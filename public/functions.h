//
// Created by OSAMA ASHRAF on 4/3/2024.
//

#ifndef RA7AL_FUNCTIONS_H
#define RA7AL_FUNCTIONS_H
#include <bits/stdc++.h>
#include "classes/List.h"
using namespace std;

// A function to split a string based on specific delimiter (space by default)
static List split(string &str, char delimiter = ' ');


// A function to join vector of string values by a delimiter
static string join(List &values, const string &delimiter);


// A function to print a vector
template<typename T>
static void printVec(vector<T> v);


// A function to convert string to appropriate data type
static Any Transform(const string &str);


///====================================================================================
///=====================================Definition=====================================
///====================================================================================
List split(string &str, char delimiter) {
    List result;
    string temp;
    for (char i: str) {
        if (i == delimiter) {
            result.append(Transform(temp));
            temp = "";
        } else {
            temp += i;
        }
    }
    result.append(Transform(temp));
    return result;
}


string join(List &values, const string &delimiter) {
    ostringstream oss;
    for (int i = 0; i < values.size(); i++)
        oss << values.getItem(i) << (i + 1 != values.size() ? delimiter : "");

    return oss.str();
}


template<typename T>
void printVec(vector<T> v) {
    cout << '{';
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << (i < v.size() - 1 ? ", " : "");
    cout << "}\n";
}


enum DataType {
    Integer, Double, Char, String
};

static DataType determineType(const string &str) {
    try {
        stod(str);
        if (str.find('.') != -1)
            return Double;
        throw std::invalid_argument("");
    } catch (const invalid_argument &) {
        try {
            stoi(str);
            for (char c: str)
                if (!isdigit(c) && c != *str.begin()) // To handle Date values
                    return String;
            return Integer;
        } catch (const invalid_argument &) {
            if (str.size() > 1)
                return String;
            return Char;
        }

    }

}

template<typename T>
static T convert(const std::string &str) {
    std::istringstream iss(str);
    T value;
    iss >> value;
    return value;
}

static Any Transform(const string &str) {
    DataType type = determineType(str);

    // Convert the string to its appropriate data type
    switch (type) {
        case Integer:
            return {convert<int>(str)};
        case Double:
            return {convert<double>(str)};
        case String:
            return {str};
        case Char:
            return {str[0]};
        default: {
            cerr << "Unexpected data type" << endl;
            return {};
        }
    }
}
#endif // RA7AL_FUNCTIONS_H

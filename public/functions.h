//
// Created by OSAMA ASHRAF on 4/3/2024.
//

#ifndef RA7AL_FUNCTIONS_H
#define RA7AL_FUNCTIONS_H
#include "public/classes/List.h"
#include <string>
#include <algorithm>
#include <QString>
using namespace std;

// A function to split a string based on specific delimiter (space by default)
[[maybe_unused]]static List split(string &str, char delimiter = ' ');


// A function to join vector of string values by a delimiter
[[maybe_unused]]static string join(List &values, const string &delimiter);


// A function to strip a string from a specific character
[[maybe_unused]]static string strip(const string &str, const string &characters = " ");


// A function to print a vector
template<typename T>
[[maybe_unused]]static void printVec(vector<T> v);


// A function to convert string to appropriate data type
[[maybe_unused]]static Any Transform(const string &str);


// A function to generate text with color
[[maybe_unused]]static QString text(string txt, string color);

// A function to initialize attribute with value
[[maybe_unused]]static QString Style(string attribute_name, string value);


// A function to remove airport code from airport name
[[maybe_unused]]static string remove_code(string airportName);

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
    for (int i = 0; i < (int)values.size(); i++)
        oss << values.getItem(i) << (i + 1 != (int)values.size() ? delimiter : "");

    return oss.str();
}


string strip(const string &str, const string &characters) {
    string result = str;
    int begin = 0;
    int end = (int)str.size() - 1;

    for(char c : result){
        if((int)characters.find(c) != -1)
            begin++;
        else
            break;
    }

    reverse(result.begin(), result.end());

    for(char c : result) {
        if ((int)characters.find(c) != -1)
            end--;
        else
            break;
    }


    return str.substr(begin, end+1);
}


template<typename T>
void printVec(vector<T> v) {
    cout << '{';
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << (i < (int)v.size() - 1 ? ", " : "");
    cout << "}\n";
}


enum DataType {
    Integer, Double, Char, String
};

static DataType determineType(const string &str) {
    try {
        stod(str);
        if ((int)str.find('.') != -1)
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
            if ((int)str.size() > 1)
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

static QString text(string txt, string color){
    ostringstream oss;
    oss<<"<font color='"<<color<<"'>";
    oss<<txt;
    oss<<"</font>";

    return QString::fromStdString(oss.str());
}

static QString Style(string attribute_name, string value){
    ostringstream oss;
    oss << attribute_name <<": "<<value<<";";
    return QString::fromStdString(oss.str());
}

static string remove_code(string airportName){
    if(*(airportName.end()-1) == ')')
        return airportName.substr(0, airportName.length()-6);
    return airportName;
}

#endif // RA7AL_FUNCTIONS_H

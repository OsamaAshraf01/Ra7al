/*
       ****   ****
 created by ahmed hamdy kotp 
       ****   ****
*/ 


#include "../include/DataFrame/CSVManager.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cmath>
using namespace std;

CSVManager::CSVManager()
{
}

CSVManager::CSVManager(const string& filename) : filename(filename) {
    data = read();
}

vector<vector<string>> CSVManager::read() {
    ifstream file(filename);
    vector<vector<string>> data;
    string line;
    while (getline(file, line)) {
        vector<string> row;
        stringstream s(line);
        string field;
        while (getline(s, field, ',')) {
            row.push_back(field);
        }
        data.push_back(row);
    }
    file.close();
    return data;
}

void CSVManager::write(const vector<vector<string>>& data) {
    ofstream file(filename);
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i != row.size() - 1) file << ",";
        }
        file << "\n";
    }
    file.close();
}

void CSVManager::addRow(const vector<string>& row) {
    data.push_back(row);
    write(data);
}

void CSVManager::deleteRow(int rowIndex) {
    if (rowIndex < data.size()) {
        data.erase(data.begin() + rowIndex);
        write(data);
    }
}

void CSVManager::updateCell(int rowIndex, int colIndex, const string& newValue) {
    if (rowIndex < data.size() && colIndex < data[rowIndex].size()) {
        data[rowIndex][colIndex] = newValue;
        write(data);
    }
}

void CSVManager::addColumn(const vector<string>& column) {
    if (column.size() == data.size()) {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i].push_back(column[i]);
        }
        write(data);
    }
}

void CSVManager::deleteColumn(int colIndex) {
    for (auto& row : data) {
        if (colIndex < row.size()) {
            row.erase(row.begin() + colIndex);
        }
    }
    write(data);
}

pair<int, int> CSVManager::findCell(const string& value) {
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            if (data[i][j] == value) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);  // Not found
}

vector<vector<string>> CSVManager::filter(function<bool(const vector<string>&)> predicate) {
    vector<vector<string>> filteredData;
    copy_if(data.begin(), data.end(), back_inserter(filteredData), predicate);
    return filteredData;
}

double CSVManager::getColumnMean(int colIndex) {
    double sum = 0.0;
    int count = 0;
    for (const auto& row : data) {
        if (colIndex < row.size()) {
            sum += stod(row[colIndex]);
            ++count;
        }
    }
    return sum / count;
}
void CSVManager::print() {
    for (const auto& row : data) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << '\n';
    }
}

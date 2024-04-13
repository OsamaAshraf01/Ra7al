//created by Ahmed Hamdy Kotp

#include "../include/DataFrame/CSVManager.h"
#include <fstream>
#include <sstream>
#include <iostream>


CSVManager::CSVManager(const string& file, delimiter) : filename(file), delimiter(delim) {}

vector<vector<string>> CSVManager::readCSV() {
    vector<vector<string>> data;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream lineStream(line);
        string cell;
        vector<string> rowData;
        while (getline(lineStream, cell, delimiter)) {
            rowData.push_back(cell);
        }
        data.push_back(rowData);
    }
    file.close();
    return data;
}

void CSVManager::writeCSV(const vector<vector<string>>& data) {
    ofstream file(filename);
    for (const auto& row : data) {
        for (int i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) file << delimiter;
        }
        file << '\n';
    }
    file.close();
}

void CSVManager::addRecord(const vector<string>& record) {
    ofstream file(filename, ios::app);
    for (int i = 0; i < record.size(); ++i) {
        file << record[i];
        if (i < record.size() - 1) file << delimiter;
    }
    file << '\n';
    file.close();
}

bool CSVManager::removeRecord(int rowIndex) {
    auto data = readCSV();
    if (rowIndex < 0 || rowIndex >= data.size()) return false;
    data.erase(data.begin() + rowIndex);
    writeCSV(data);
    return true;
}

bool CSVManager::updateRecord(int rowIndex, const vector<string>& newRecord) {
    auto data = readCSV();
    if (rowIndex < 0 || rowIndex >= data.size()) return false;
    if (newRecord.size() != data[rowIndex].size()) return false;
    data[rowIndex] = newRecord;
    writeCSV(data);
    return true;
}

//Created by Ahmed Hamdy Kotp

#ifndef CSVMANAGER_H
#define CSVMANAGER_H

#include <vector>
#include <string>

using namespace std;

class CSVManager {
private:
    string filename;
    char delimiter = ',';

public:
    CSVManager(const string& file, delimiter);
    vector<vector<string>> readCSV();
    void writeCSV(const vector<vector<string>>& data);
    void addRecord(const vector<string>& record);
    bool removeRecord(int rowIndex);
    bool updateRecord(int rowIndex, const vector<string>& newRecord);
};

#endif // CSVMANAGER_H

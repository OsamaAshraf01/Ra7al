/*
   *   
 *   created by ahmed hamdy kotp   
   *   
*/

/*
* CSV_Manager:
* - Counstructor should be initialized with the directory of the file. 
  *******************CSV_Manager myCSV("data.csv");**********************
  * 
* - Read/Write CSV data     ===>> myCSV.read();
* 
* - Add/Delete rows/columns == > vector<string> newRow = {"Ahmed", "19", "DSAI"};
                                 myCSV.addRow(newRow);

                                 vector<string> newColumn = {"ID", "1", "2", "3"};
                                 myCSV.addColumn(newColumn);

*                                myCSV.deleteColumn(0);

* - Update cells  =====>> myCSV.updateCell(row, col, "19");
* 
* 
* - Find cells by content , Filter data
* 
* // Find cell containing "Sales"
     pair<int, int> salesCell = myCSV.findCell("Sales");

// Filter rows where the second column contains "25" 
    vector<vector<string>> filteredData = myCSV.filter([](const vector<string>& row) {
    return row[1] == "25";
});

// Get mean of the third column (assuming numerical data)
    double meanSalary = myCSV.getColumnMean(2);

* - Print CSV contents==> myCSV.print();

*/
#ifndef CSV_MANAGER_H
#define CSV_MANAGER_H
#include <vector>
#include <string>
#include <functional>

using namespace std;

class CSVManager {
public:
    CSVManager();
    CSVManager(const string& filename);
    vector<vector<string>> read();
    void write(const vector<vector<string>>& data);
    void addRow(const vector<string>& row);
    void deleteRow(int rowIndex);
    void updateCell(int rowIndex, int colIndex, const string& newValue);
    void addColumn(const vector<string>& column);
    void deleteColumn(int colIndex);
    pair<int, int> findCell(const string& value);
    vector<vector<string>> filter(function<bool(const vector<string>&)> predicate);
    double getColumnMean(int colIndex);
    void print();

private:
    string filename;
    vector<vector<string>> data;
};
#endif
